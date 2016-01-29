#include <stdio.h>
#include "alg.h"
#include <memory.h>

void insert_sort(int* arr, int size);

void merge(int* arr, int head, int mid, int tail);
void merge_sort(int* arr, int head, int tail);

int main(int argc, char const *argv[])
{
	const int size = 10;
	int arr[size];

	for (int i = 0; i < size; ++i)
	{
		arr[i] = random_int(1, 99);
	}
	print(arr, size);

	// insert_sort(arr, size);
	// print(arr, size);

	// merge(arr, 3, 4, 7);
	merge_sort(arr, 0, size - 1);
	print(arr, size);

	return 0;
}

void insert_sort(int* arr, int size)
{
	for (int i = 1; i < size; ++i)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[i] < arr[j])
			{
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

// merge [head, mid] array, and [(mid + 1), tail] array
void merge(int* arr, int head, int mid, int tail)
{
	printf("merge head: %d, mid %d, tail %d\n", head, mid, tail);
	int i1 = head;
	int i2 = mid + 1;
	int sorted[tail - head + 1];
	for (int i = 0; i < tail - head + 1; ++i)
	{
		int next;
		if(i1 > mid) 
		{ 
			next = arr[i2]; 
			i2++; 
			// printf("1: %d\n", next); 
		}
		else if(i2 > tail) 
		{ 
			next = arr[i1]; 
			i1++; 
			// printf("2: %d\n", next); 
		}
		else 
		{ 
			next = arr[i1] <= arr[i2] ? arr[i1] : arr[i2]; 
			if(arr[i1] <= arr[i2]) i1++;
			else i2++;
			// printf("3: %d\n", next); 
		}

		sorted[i] = next;
	}
	memcpy(arr + head, sorted, (tail - head + 1) * sizeof(int));
}

void merge_sort(int* arr, int head, int tail)
{
	if(head >= tail) return;
	int mid = (tail + head) / 2;
	merge_sort(arr, head, mid);
	merge_sort(arr, mid + 1, tail);
	merge(arr, head, mid, tail);
}