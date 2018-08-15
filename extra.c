#include "extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
	int top;
	int arr[MAX];
};

Stack stack_create(){
	Stack s = (Stack) malloc (sizeof(struct stack));
	s->top = -1;
	return s;
}

void stack_destroy(Stack sP){
	free (sP);
}

void push(Stack s, int i){

	if (s->top == MAX-1)	//SAME AS if (s->size==MAX)
		printf("STACK OVERFLOW\n");
	else
		s->arr[++(s->top)] = i;	//SAME AS: ++(s->top);	s->arr[s->top] = i;
}

int top(Stack s){
	if (s->top == -1)	//SAME AS if (s->size==0)
	{
		printf("STACK UNDERFLOW\n");
		return -1;	//error value (meaning an overflow or an underflow)
	}
	return s->arr[s->top];
}

int pop(Stack s){
	if (s->top==-1)	//SAME AS if (s->size==0)
	{
		printf("STACK UNDERFLOW\n");
		return -1;
	}
	else
		return s->arr[(s->top)--];	//SAME AS int temp = s->arr[s->top];	--(s->top);		return temp;
}

/////////////////////////////QUEUE////////////////////////////////////////

struct queue{
	Stack stack1;
	Stack stack2;
	int size;
};

Queue queue_create(){
	Queue qP = (Queue) malloc (sizeof(struct queue));	//alocate memmory
	qP->size = 0;
	qP->stack1 = stack_create();
	qP->stack2 = stack_create();
	return qP;
}

void queue_destroy(Queue q){
	stack_destroy(q->stack1);
	stack_destroy(q->stack2);
	free (q);
}

void enqueue(Queue q, int i){
	if(q->size==MAX2)
		printf("QUEUE OVERFLOW\n");
	else
	{
		push(q->stack1, i);	//simply push new item onto stack1 :)
		++(q->size);
	}
}

int peek(Queue q){
	int aux;

	if(q->stack1->top == -1 && q->stack2->top == -1)//If both stacks are empty then error
	{
		printf("QUEUE UNDERRFLOW\n");
		return -1;
	}
	if(q->stack2->top == -1)//if stack2 is empty
	{

		while(q->stack1->top != -1)	//while stack1 is not empty, move everything from stack1 to stack2 by poppin and pushin
		{
			aux = pop(q->stack1);	//this way, you sorta reverse the order of the things in the stack
			push(q->stack2, aux);

		}
	}
	aux = top(q->stack2);	//Get the last element from stack2 (which was originally the first element of stack1 LOL)

	return aux;
}

int dequeue(Queue q){
	int aux;

	if(q->stack1->top == -1 && q->stack2->top == -1)//If both stacks are empty then error						(q->size==0)
	{
		printf("QUEUE UNDERRFLOW\n");
		return -1;
	}

	if(q->stack2->top == -1)//if stack2 is empty
	{
		while(q->stack1->top != -1)	//While stack1 is not empty, move everything from stack1 to stack2 by poppin and pushin
		{
			aux = pop(q->stack1);	//this way, you sorta reverse the order of the things in the stack
			push(q->stack2, aux);
		}
	}
	aux = pop(q->stack2);	//Pop the last element from stack2 (which was originally the first element of stack1 LOL)
	--(q->size);
	return aux;
}


