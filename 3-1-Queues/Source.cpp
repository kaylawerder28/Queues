#include <iostream>
using namespace std;

class Queue {
public:
	int *A;
	int front = -1;
	int rear = -1;
	int aSize; 
	Queue() {}
	Queue(int n) { A = new int[n]; aSize = n; }
	void Enque(int x) {
		if (isFull()) { cout << "No space to add element" << endl; return; }
		if (isEmpty()) { front++; } // if it is empty and we add an element, it updates the front and rear to array position 0 where the first element was added
		//rear++; // if there is already an element in the array, we update the rear so that the front stays at the first element added but the rear updates to the next element added
		rear = (rear + 1) % aSize; 
		A[rear] = x;
	}
	bool isEmpty() {
		if (front == -1 && rear == -1) { return true; } // queue is EMPTY
		else return false;
	}
	bool isFull() {
		// if (rear == aSize - 1) return true; // if the rear is equal to the size of the queue-1, it is FULL
		if (front == (rear + 1) % aSize) return true;
		else return false;
	}
	void Print() {
		if (isEmpty()) { cout << "Error: Nothing to print" << endl; return; }
		if (front > rear) // meaning we have a circular queue (front spots are not full, but rear is )
		{
			for (int i = front; i < aSize; i++)
				cout << A[i] << " ";
			for (int i = 0; i <= rear; i++)
				cout << A[i] << " ";
		}
		else { // for normal queue
			for (int i = front; i <= rear; i++) {
				cout << A[i] << " ";
			}
		}
			cout << endl;
	}
	void Deque() {
		if (front == rear && front != -1) {		// if front == rear, there is only one element in the array, if front != -1 there is an element in the array
			// set the front and rear = -1 because now there is no element in the list
			front = -1;
			rear = -1;
		}
		else {
			front = (front + 1) % aSize;
		}
	}
	int DequeBack(){
		int value = A[front];
		return value;
	}
};

class Node {
public:
	int data; 
	Node * next; 
	Node() {}
	Node(int x) { data = x; next = nullptr; }
	};
class DQueue {
public:
	Node * front;
	Node * rear;
	DQueue() { front = nullptr; rear = nullptr; }
	bool isEmpty() {
		if (front == nullptr && rear == nullptr) return true;
		else return false;
	}
	bool isLastNode() {
		if (front == rear && front != nullptr) return true;
		else return false;
	}
	void Enque(int x) {
		Node * node = new Node(x);
		if (isEmpty()) {
			front = node;
			rear = node;
		}
		else {
			rear->next = node;
			rear = node;
		}
	}
	void Deque() {
		if (isLastNode()) {
			rear = nullptr;
		}
		Node *temp = front;
		front = front->next;
		delete temp;
	}
	void Print() {
		Node * temp = front;
		if (isEmpty()) { cout << "Nothing to print" << endl; return; }
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main()
{
	//Queue * queue = new Queue(6);
	Queue * queue = new Queue(6);
	queue->Enque(5);	queue->Print(); // 5
	queue->Enque(10);	queue->Print(); // 5 10
	queue->Enque(15);	queue->Print(); // 5 10 15
	queue->Enque(20);	queue->Print(); // 5 10 15 20
	queue->Enque(25);	queue->Print(); // 5 10 15 20 25
	queue->Enque(30);	queue->Print(); // 5 10 15 20 25 30
	queue->Deque();		queue->Print(); // 10 15 20 25 30
	//queue->Enque(35);	 // No space to add element
	queue->Deque();		queue->Print(); // 15 20 25 30
	cout << queue->DequeBack() << endl; // 15
	queue->Deque();		queue->Print(); // 20 25 30
	queue->Deque();		queue->Print(); // 25 30
	queue->Deque();		queue->Print(); // 30
	queue->Deque();		 // Error: Nothing to print
	getchar();
	getchar();
}