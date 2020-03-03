//   Serial	Number	/	s	: 13
//
//   Author/s:	Jeremiah Lopez
//	 Due Date:  3/4/2020
//	 Programming Assignment	Number	3
//
//	 Spring	2020 -	CS	3358 -	253
//
//	 Instructor: Husain	Gholoom.
//
// 	<Brief	description	of	the		purpose	of	the	program>

#include <iostream>
#include <string>

using namespace std;

class LinkedStack{
    struct Node{
    char data;
    struct Node *next;
    };
Node *top = NULL;
public:
    LinkedStack(){
    top = nullptr;
    stackSize = 0;
    }

    ~LinkedStack(){
        Node* tempNode;
        while(top){
            tempNode = top;
            delete top;
            top = tempNode->next;
        }

        delete tempNode;
    }

    void push(char lett){
        Node *n = new Node();
        n->data = lett;
        n->next = top;
        top = n;
        stackSize++;
    }

    bool isEmpty(){
        if(top == NULL)
            return true;
        else
            return false;
    }

    char pop(){
        if(top != nullptr){
            char value = top->data;
            Node * tempNode = top;
            delete top;

            top = tempNode->next;
            delete tempNode;

            return value;
        }
        else{
            cout << "Empty stack" << endl;
            return 0;
        }
    }

    int getSize(){
        return stackSize;
    }

private:
    int stackSize;
};

class LinkedQueue{
    struct Qnode{
        char data;
        Qnode* next;
        Qnode(char lett){
            data = lett;
            next = NULL;
            }
    };

public:
    LinkedQueue(){

    }
};

void details();
void menu();
void exit();
void createStack(LinkedStack &, LinkedStack &);

int main()
{
    int choice;
    LinkedStack str1;
    LinkedStack str2;

    details();
    menu();
    cin >> choice;

    do{
        switch(choice){
        case 1:
            createStack(str1 , str2 );
            break;
        case 2:
            break;
        case 9:
            exit();
            break;
        default:
            cout << "Invalid Option.\n\n";
            menu();
            cin >> choice;
        }
    }while(choice == 1 || choice == 2 || choice == 9);



}

void details(){
    cout << "*** Welcome to My stack / Queue Program ***\n\n"
         << "The function of this program is to :\n\n"
         << "\t1. Use stack to determine whether or not\n\t"
         << "   two strings are the same.\n\n"
         << "\t2. Use queue to determine whether or not\n\t "
         << "  STRING2 is the reversed of STRING1.\n\n";
}

void menu(){
    cout << "Select from the following menu\n"
         << "\t1.\tEnter Stack Values.\n"
         << "\t2.\tEnter Queue Values.\n"
         << "\t9.\tTerminate the program.\t\t";
}

void exit(){
    cout << "*** End of the program. ***/n"
         << "*** Written by Jeremiah Lopez ***/n"
         << "*** March 2nd 2020 ***/n/n";
}

void createStack(LinkedStack & charStack1 , LinkedStack & charStack2 ){
    string vals;
    int location;
    int larger;
    char lett;

    cout << "Enter Stack Values:\t";
    cin >> vals;

    for(int i =0; i < vals.size(); i++){
        if(vals.at(i) != '#'){
            //cout << vals.at(i);
            lett = vals.at(i);
            charStack1.push(lett);
        }
        else{
            location= i;
            break;
        }
    }
    for(int i=0; i < vals.size(); i++){
        if(i <= location)
            continue;
        else{
            //cout << vals.at(i);
            lett = vals.at(i);
            charStack2.push(lett);
        }
    }

    if(charStack1.getSize() > charStack2.getSize())
        larger = charStack1.getSize();
    else if(charStack2.getSize() > charStack1.getSize())
        larger = charStack2.getSize();
    else if(charStack1.getSize() == charStack2.getSize())
        larger = charStack1.getSize();

    for(int i=0; i<larger; i++){
        if(charStack1.pop() == charStack2.pop()){
            cout << "Strings are identical.";
            break;
        }
        else
            cout << "Strings are not Identical.";
            break;

    }

}
