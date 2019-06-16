typedef struct{
	int *a;
	int mxsz;
	int *nextp;
}vecdt_t;

vecdt_t *init(int initSize);
int size(vecdt_t *vector), at(vecdt_t *vector, int index);
void insert(vecdt_t *vector, int value),
     increase(vecdt_t *vector);  
