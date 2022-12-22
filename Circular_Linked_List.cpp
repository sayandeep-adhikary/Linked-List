#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this ->data = data;
        this ->prev = NULL;
        this ->next = NULL;
    }
};

void insertNode(Node* &tail, int element, int data){
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;

    }
    else{
        Node* cur = tail;
        while(cur->data != element){
            cur = cur->next;
        }
        Node* temp = new Node(data);
        temp->next = cur->next;
        cur->next = temp;
    }
}

void printLL(Node* &tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    do{
        cout<< temp->data<< " ";
        temp = temp->next;
    }while(tail != temp);
    cout<<"\n";
}

void deleteNode(Node* &tail, int data){
    if(tail == NULL){
        cout<<"List is empty, please try again!"<<endl;
        return;
    }
    else{
        Node* previous = tail;
        Node* current = previous->next;
        while(current->data != data){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        if(current == previous) tail = NULL;
        else if(tail == current) tail = previous;
        current->next = NULL;
        delete current;
    }
}
int main()
{
    Node* tail = NULL;
    insertNode(tail, 5, 3);
    printLL(tail);
    insertNode(tail, 3, 5);
    printLL(tail);
    deleteNode(tail, 3);
    printLL(tail);
    deleteNode(tail, 5);
    printLL(tail);
    return 0;
}