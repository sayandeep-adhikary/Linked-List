#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* address;
    Node(int data){
        this ->data = data;
        this ->address = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    // create a new node
    Node* temp = new Node(data);
    temp ->address = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->address = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp ->address;
        count++;
    }
    if(temp->address == NULL){
        insertAtTail(tail, data);
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->address = temp->address;
    temp->address = nodeToInsert;
}

void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        head = head->address;
        temp->address = NULL;
        delete temp;
    }
    else{
        Node* current = head;
        Node* previous = NULL;
        int count = 1;
        while(count<position){
            previous = current;
            current = current->address;
            count++;
        }
        previous->address = current->address;
        current->address = NULL;
        delete current;
    }
}
void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->address;
    }cout<<"\n";
    
}
int main()
{
    Node* node1 = new Node(10);
    // cout << node1 -> data<<endl;
    // cout<< node1 -> address<<endl;

    Node* head = node1;
    Node* tail = node1;
    printLL(head);
    insertAtTail(tail, 12);
    printLL(head);
    insertAtTail(tail, 15);
    printLL(head);
    insertAtPosition(head, tail, 4, 22);
    printLL(head);
    deleteNode(4, head);
    printLL(head);
    return 0;
}