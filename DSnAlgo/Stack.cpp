#include <stdio.h>
#define STACK_SIZE 100
class MyStack {
	int data[STACK_SIZE];
	int n = 0;
public:
	void push(int v);
	bool isEmpty();
	bool isFull();
	int pop();
	void clear();
};

bool MyStack::isEmpty() {
	return n == 0;
}

bool MyStack::isFull() {
	return n == STACK_SIZE;
}

void MyStack::clear() {
	n = 0;
}

void MyStack::push(int v) {
	if (isFull()) {
		printf("Stack is full!\n");
		return;
	}
	data[n++] = v;
}

int MyStack::pop() {
	if (isEmpty()) {
		printf("Stack is empty!\n");
		return 0;
	}
	return data[--n];
}

int main() {
	MyStack stack;

	int i = 0;
	while(!stack.isFull()){
		stack.push(i++);
	}

	while (!stack.isEmpty()) {
		printf("%d ", stack.pop());
	}
	printf("\n");

	printf("Done.\n");
	return 0;
}