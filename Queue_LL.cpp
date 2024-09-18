#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class Queue{

    public:
    Node<T> *front;
    Node<T> *rear;

    Queue(){
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(T x){

        Node<T> *newNode = new Node<T>(x);

        if(isEmpty()){
            front = newNode;
            rear = newNode;
            return;
        }

        rear->next  = newNode;
        rear = newNode;

    }

    void dequeue(){

        if(isEmpty()){
            cout<<"Queue is empty!";
            return;
        }

        Node<T> *temp = front;
        if(front==rear){
            front = nullptr;
            rear = nullptr;
            delete temp;
        }else{
            front = front->next;
            delete temp;
        }

    }

    T getFront(){
        if(isEmpty()){
            cout<<"Queue is empty!";
            return T();
        }
        return front->data;
    }

    bool isEmpty(){
        if(front==nullptr){
            return true;
        }

        return false;

    }

    void printQueue(){
        Node<T> *temp = front;

        while(temp!=nullptr){
            cout<< temp->data << " ";
            temp = temp->next;
        }

    }
    
};

int main(){

    Queue<int> q;

    q.enqueue(5);
    q.enqueue(2);
    q.dequeue();
    q.dequeue();
    q.printQueue();


    return 0;
}