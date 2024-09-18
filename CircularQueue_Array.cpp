#include <iostream>
using namespace std;

#define SIZE 10

template <class T>
class CircularQueue {

    T arr[SIZE];
    int front;
    int rear;

public:

    CircularQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(T x) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }

        T element = arr[front];

        if (front == rear) {  // When only one element is present
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        return element;
    }

    T getFront() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }
        return arr[front];
    }

    T getRear() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return T();
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    int size() {
        if (isEmpty()) {
            return 0;
        }

        if (rear >= front) {
            return rear - front + 1;
        } else {
            return SIZE - front + rear + 1;
        }
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << arr[rear] << endl;  // Print the last element
    }
};

int main() {
    CircularQueue<int> q;

    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.printQueue();

    return 0;
}
