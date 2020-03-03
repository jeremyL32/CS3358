//	 Author	/ s	:	Jeremiah Lopez
// Serial	Number: 13
//
//	 Due	Date : 2/19/2020
//	 Programming Assignment	Number 2
//	 Spring	2020 - CS 3358 - Section Number 253
//
//	 Instructor: Husain	Gholoom.
//
// 	The purpose of this program is to create a matrix whose rows, columns,
//      and diagonals consist of unique numbers that add to a perfect number

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <time.h>

using namespace std;

void description();

int getPerfectNumber(int);

int validation(int);

void createVector(vector<vector<int> > &, int);

void addRows(vector<vector<int> > &, int, int, bool &);

void addColumns(vector<vector<int> > &, int, int, bool &);

void addDiag(vector<vector<int> > &, int, int, bool &);

int main()
{
    const int smallestNum = 1; //the smallest acceptable size
    const int largestNum = 12; //the largest acceptable size

    int matrixSize; //the size of the matrix to be inputted by the user
    int perfectNum; //determined perfect matrix property number
    bool perfectCheck = true; //checks if rows/cols/diags satisfy perfect matrix
                              //property
    bool another = true; // checks if user wants another matrix
    char choice; //choice when asked if another matrix is desired

    description();

    cout << "Enter the size of the matrix: ";
    cin >> matrixSize;

    while(matrixSize < smallestNum || matrixSize >= largestNum)
    {
        cout << "Matrix size is out of the acceptable range.\n"
             << "Please enter a number within 2 - 13: ";

        cin >> matrixSize;
    }

    perfectNum = getPerfectNumber(matrixSize);

    vector<vector<int> > rows(matrixSize, (vector<int>(matrixSize)));

    createVector(rows, matrixSize);

    cout << "The perfect Number is: " << perfectNum << endl << endl;

    addRows(rows, matrixSize, perfectNum, perfectCheck);

    addColumns(rows, matrixSize, perfectNum, perfectCheck);

    addDiag(rows, matrixSize, perfectNum, perfectCheck);

    if(perfectCheck == false)
    {
        cout << "\nThis is not a perfect Matrix. \n\n";
    }

    do
    {
        cout << "Would you like to find another perfect matrix "
         << " - Enter y or Y for yes or n or N for no: ";
        cin >> choice;
        switch(choice)
        {
            case 'y' :
            case 'Y' :
                {
                    cout << "\nEnter the size of the matrix: ";
                    cin >> matrixSize;

                    while(matrixSize < smallestNum || matrixSize >= largestNum)
                    {
                        cout << "Matrix size is out of the acceptable range.\n"
                        << "Please enter a number within 2 - 13: ";

                        cin >> matrixSize;
                    }

                    perfectNum = getPerfectNumber(matrixSize);

                    vector<vector<int> > rows(matrixSize, (vector<int>(matrixSize)));

                    createVector(rows, matrixSize);

                    cout << "The perfect Number is: " << perfectNum << endl << endl;

                    addRows(rows, matrixSize, perfectNum, perfectCheck);

                    addColumns(rows, matrixSize, perfectNum, perfectCheck);

                    addDiag(rows, matrixSize, perfectNum, perfectCheck);

                    if(perfectCheck == false)
                    {
                        cout << "\nThis is not a perfect Matrix. \n\n";
                    }
                break;
            }
            case 'n' :
            case 'N' :
                cout << "\n\nThis algorithm is Implemented by Jeremiah Lopez \n\nFebruary 19, 2020\n\n";
                another = false;
                break;
            default:
                cout << "\nInvalid response - Please enter y|Y or n|N\n\n";
        }
    }while(another != false);

    return 0;
}

void description()
{

    cout << "Welcome to my perfect matrix program. "
         << "The function of the program is to:\n\n"
         << "\t1. Allow the user to enter the size of the perfect matrix, "
         << "such as N. N >=2 and < 13.\n\n"
         << "\t2. Create a 2 D vector array of size N x N.\n\n"
         << "\t3. Populate the 2 D vector array with distinct "
         << "random numbers.\n\n"
         << "\t4. Display the perfect number , sum for each row, column,"
         << " and\n\n"
         << "\t   diagonals then determine whether the numbers "
         << "in N x N vector\n\n"
         << "\t   array are perfect matrix numbers.\n\n\n";

}

int getPerfectNumber(int s)
{

    int num = s *((s*s)+1)/2;
    return num;

}

void createVector(vector<vector<int> > &r, int s)
{
    srand(time(NULL));

    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {

            int num = rand() % 9 + 1;
            r[i][j] = num;

        }
    }

    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            if(r[i][j+1] == r[i][j])
            {
                int num = rand() % 9 + 1;
                r[i][j+1] = num;
            }
        }
    }


    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            cout << r[i][j] << " ";
        }
        cout << endl << endl;
    }

}

void addRows(vector<vector<int> > &r, int s, int n, bool & perfect )
{
    int sum = 0;
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            sum += r[i][j];
        }
        cout << "Sum of row # " << (i+1) << ": " << sum << " " << endl;

        if(sum !=n )
            perfect = false;

        sum = 0;
    }
    cout << endl;
}

void addColumns(vector<vector<int> > &r, int s, int n, bool & perfect)
{
    int sum = 0;
    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            sum += r[j][i];
        }
        cout << "Sum of column # " << (i+1) << ": " << sum << " " << endl;

        if(sum !=n )
            perfect = false;

        sum = 0;
    }
    cout << endl;
}

void addDiag(vector<vector<int> > &r, int s, int n,
             bool & perfect)
{
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < s; i++)
    {
        sum1 += r[i][i];
    }

    cout << "sum of diagonal #1: " << sum1 << endl;

    if(sum1 !=n )
        perfect = false;

    for(int i = 0; i < s; i++ )
    {
        int num = s-(i+1);
        sum2 += r[i][num];
    }

    cout << "sum of diagonal #2: " << sum2 << endl;

    if(sum2 !=n )
        perfect = false;

}
