#include <stdio.h>
#include "duvector.h"
#include <stdlib.h>

int main()
{
	vecdt_t *vector;

	vector = init(5);
	printf("value at position 5 is a %d\n", at(vector, 5));	

	free(vector->a);
	free(vector);

	return 0;	
}
