#include <stdlib.h>
#include <stdio.h>
#include "duvector.h"

vecdt_t *init(int sz)
{
	vecdt_t* v;
	
	v = malloc(sizeof(vecdt_t));
	v->mxsz = sz;	
	v->a = malloc(sizeof(int) * sz);
	v->nextp = v->a;
	
	return v;
}

int size(vecdt_t *v)
{
	return v->nextp - v->a;
}

void insert(vecdt_t *v, int val)
{
	int sz;  

	sz = size(v);
	if(sz == v->mxsz)
		increase(v);
	
	*v->nextp++ = val;	
}

int at(vecdt_t *v, int index)
{
	if((v->a + index) < (v->a + v->mxsz))
		return v->a[index];

	fprintf(stderr, "Index is out of range.\n");
	exit(EXIT_FAILURE);
}

void increase(vecdt_t *v)
{
	int *temp, *tp, *p;

	temp = malloc(sizeof(int) * (v->mxsz*2));
	tp = temp;
	p = v->a;

	for(;v->nextp - p;)
		*tp++ = *p++; 
	
	free(v->a);

	v->a = temp;
	v->mxsz = v->mxsz*2;
	v->nextp = tp;
}
