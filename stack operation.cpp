#include <stdio.h>
#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};
void initialize(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push %d\n", value);
    } else {
        stack->top++;
        stack->arr[stack->top] = value;
    }
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    } else {
        int poppedValue = stack->arr[stack->top];
        stack->top--;
        return poppedValue;
    }
}
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements in the stack: ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    int poppedValue = pop(&stack);
    if (poppedValue != -1) {
        printf("Popped element: %d\n", poppedValue);
    }

    display(&stack);

    return 0;
}