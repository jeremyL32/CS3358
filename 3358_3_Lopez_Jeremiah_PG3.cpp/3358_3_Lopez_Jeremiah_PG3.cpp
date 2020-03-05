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
// 	 This assignment is using stack and queue ADT to determine
//   if a string entered by a user (separator included) is either
//   the same or the reverse of the first stack/queue

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
            this->data = lett;
            next = NULL;
            }
    }*p=NULL;

public:
    Qnode *front, *rear;
    LinkedQueue(){front=rear=NULL; queueSize=0;}
    ~LinkedQueue(){
    Qnode* tempNode;
        while(front){
            tempNode = front;
            delete front;
            front = tempNode->next;
        }

        delete tempNode;
        queueSize=0;}

    void enqueue(char lett){
        queueSize++;
        Qnode *temp=new Qnode(lett);
        if(temp==NULL){
            cout<<"Overflow"<<endl;
            return;
        }
        temp->data=lett;
        temp->next=NULL;

        //for first node
        if(front==NULL){
            front=rear=temp;
        }
        else{
            rear->next=temp;
            rear=temp;
        }

    }

    char dequeue(){
        char temp;
        if(front == NULL){
            return 0;
        }
        else{
            p = front;
            temp = p->data;
            front = front->next;
            delete(p);
            return(temp);
        }

    }
    void rev(){

        Qnode* curr = front;
        Qnode *p = NULL, *next = NULL;
        while( curr != NULL){
            next = curr->next;
            curr->next = p;
            p = curr;
            curr = next;
        }
        front = p;
    }

    int getSize(){
        return queueSize;
    }
    void resetSize(){
    queueSize=0;}
private:
    int queueSize;
    int numItems;
};

void details();
void menu();
void exit();
void createStack(LinkedStack &, LinkedStack &);
void createQueue(LinkedQueue &, LinkedQueue &);

int main()
{
    int choice;     //choice from user
    bool loop = true;       //loop determinate
    LinkedStack str1;
    LinkedStack str2;
    LinkedQueue qStr1 ;
    LinkedQueue qStr2 ;

    details();
    menu();
    cin >> choice;

    do{
        switch(choice){
        case 1:
            createStack(str1 , str2 );
            menu();
            cin >> choice;
            break;
        case 2:
            createQueue(qStr1, qStr2);
            qStr1.resetSize();
            qStr2.resetSize();
            menu();
            cin >> choice;
            break;
        case 9:
            loop = false;
            exit();
            break;
        default:
            cout << "Invalid Option.\n\n";
            menu();
            cin >> choice;
            break;
        }
    }while(loop);



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
    cout << "*** End of the program. **\/n"
         << "*** Written by Jeremiah Lopez ***\n"
         << "*** March 2nd 2020 ***\n\n";
}

void createStack(LinkedStack & charStack1 , LinkedStack & charStack2){
    string vals;        //string from user
    int location;       //index of separator
    int larger;         //size of larger stack
    char lett;          //char from string
    bool checker;       //bool for in order check

    cout << "Enter Stack Values:\t";
    cin >> vals;

    for(int i =0; i < vals.size(); i++){
        if(vals.at(i) != '#'){
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
            continue;
        }
        else{
            checker = false;
            break;
        }
    }

    if(checker == false){
        cout << "Strings are not Identical.\n\n";
    }
    else{
        cout << "Strings are identical.\n\n";
    }

}

void createQueue(LinkedQueue & charQueue1, LinkedQueue & charQueue2){
    string vals;        //string from user
    int location;       //index of separator
    int larger;         //the larger queue
    char lett;          //letter from string
    bool checker;       //bool for reverse check

    cout<< "Enter Queue Values.\t";
    cin>> vals;

    for(int i =0; i < vals.size(); i++){
        if(vals.at(i) != '#'){
            lett = vals.at(i);
            charQueue1.enqueue(lett);
        }
        else{
            location= i;
            break;

        }
    }
    for(int i=0; i < vals.size(); i++){
        if(i <= location){
            continue;
        }
        else{
            lett = vals.at(i);
            charQueue2.enqueue(lett);
        }
    }

    if(charQueue1.getSize() > charQueue2.getSize())
        larger=charQueue1.getSize();
    else if(charQueue1.getSize() < charQueue2.getSize())
        larger=charQueue2.getSize();
    else if(charQueue1.getSize() == charQueue2.getSize())
        larger=charQueue1.getSize();

    charQueue2.rev();

    for(int i = 0; i < larger; i++){
        if(charQueue1.dequeue() != charQueue2.dequeue()){
            checker = false;
            break;
        }
    }

    if(checker==false){
        cout << "Strings are not reversed.\n\n";
    }
    else{
        cout << "Strings are reversed.\n\n";
    }
    checker = true;
}
