#include <stdio.h>
#include <stdlib.h>
#include "extra.h"

int main(){
	setbuf(stdout, 0);
	Queue myQueue = queue_create();
	int aux[12]; //arreglo estatico de variables auxiliares

	printf("Escribe 12 numeros que quieres encolar\n");
	for (int i = 0; i < 12; i++)
	{
		scanf("%d", &aux[i]);
		enqueue(myQueue, aux[i]);
	}

	int auxx  = dequeue(myQueue);
	if (auxx != -1)
		printf("%d\n", auxx);

	auxx = dequeue(myQueue);
	if (auxx != -1)
		printf("%d\n", auxx);

	auxx = dequeue(myQueue);
	if (auxx != -1)
		printf("%d\n", auxx);

	auxx = peek(myQueue);
	if (auxx != -1)
		printf("%d\n", auxx);

	auxx = peek(myQueue);
	if (auxx != -1)
		printf("%d\n", auxx);

	queue_destroy(myQueue);
	return 0;
}
