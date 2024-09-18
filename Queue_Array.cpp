#include <iostream>
using namespace std;


#define SIZE 10

template <class T>
class Queue{

    int arr[SIZE];
    int front;
    int rear;


    public:


    Queue(){
        front = -1;
        rear = -1;

    }

    void enqueue(T x){

        if(isFull()){
            cout<<"Queue is Full!";
            return;
        }
        if(isEmpty()){
            front = 0;
            rear = 0;
            arr[rear] = x;
            return;
        }

        rear++;
        arr[rear] = x;

    }
    
    T dequeue(){

        if(isEmpty()){
            cout<<"Queue is Empty!";
            return T();
        }

        if (front==rear){
            T element = arr[front];
            front = -1;
            rear = -1;
            return element;
        }

        T element = arr[front];
        front++; 

        return element;
    }

    T getFront(){
        if(isEmpty()){
            return T();
        }
        return arr[front];
    }

    T getRear(){

        if(isEmpty()){
            return T();
        }
        return arr[rear];

    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }

        return false;
    }

    bool isFull(){
        if(rear==SIZE-1){
            return true;
        }
        return false;
    }

    
    int size(){

        if(isEmpty()){
            return 0;
        }

        int size = (rear-front) +1;

        return size;
    }

    void printQueue(){

        if(isEmpty()){
            cout<<"Queue is Empty!";    
            return;    
        }    

        for(int i = front; i<=rear; i++){
            cout<< arr[i]<< " ";
        }

        cout<<endl;
    }
    

};


int main(){

    Queue<int> q;

    q.enqueue(5);
    q.enqueue(6);
    q.printQueue();
    return 0;
}