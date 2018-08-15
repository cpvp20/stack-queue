#define MAX 50
#define MAX2 100
#ifndef EXTRA_H_
#define EXTRA_H_

typedef struct stack * Stack;

typedef struct queue * Queue;

Queue queue_create();
void queue_destroy(Queue);

void enqueue(Queue, int);
int peek(Queue);
int dequeue(Queue);

#endif /* EXTRA_H_ */
