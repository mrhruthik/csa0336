#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int isEmpty() {
    return front == -1 && rear == -1;
}
int isFull() {
    return rear == MAX_SIZE - 1;
}
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = data;
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}