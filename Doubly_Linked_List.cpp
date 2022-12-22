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

void printLL(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<"\n";
}

int getLength(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* head, Node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(count<position-1){
        temp = temp ->next;
        count++;
    }
    if(temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* current = head;
        Node* previous = NULL;
        int count = 1;
        while(count<position){
            previous = current;
            current = current->next;
            count++;
        }
        current->prev = NULL;
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}
int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    printLL(head);
    insertAtHead(head, 12);
    printLL(head);
    insertAtHead(head, 14);
    printLL(head);
    insertAtHead(head, 16);
    printLL(head);
    insertAtTail(tail, 18);
    printLL(head);
    insertAtTail(tail, 20);
    printLL(head);
    insertAtPosition(head, tail, 7, 24);
    printLL(head);
    deleteNode(1, head);
    printLL(head);
    deleteNode(2, head);
    printLL(head);
    deleteNode(3, head);
    printLL(head);
    deleteNode(4, head);
    printLL(head);
    deleteNode(3, head);
    printLL(head);
    return 0;
}