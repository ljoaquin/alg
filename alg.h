// just make life easier
#include <stdlib.h>
#include <time.h>

inline void print(int* arr, int size);
inline int random_int(int min = 1, int max = 100);

int random_int(int min, int max)
{
	static int seed = 0;
	if(!seed++) srand(time(NULL)); // lazy
	return (rand() % (max + 1 - min)) + min;
}

void print(int* arr, int size)
{
	printf("[ ");
	for (int i = 0; i < size; ++i)
	{
		printf("[%d]%d, ", i, arr[i]);
	}
	printf("]\n");
}