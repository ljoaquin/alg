#include <stdio.h>
#include "alg.h"

int peak(int* arr, int head, int tail);
bool is_peak(int* arr, int size, int index);

int main(int argc, char const *argv[])
{
	const int size = 100;
	int arr[size];

	for (int i = 0; i < size; ++i)
	{
		arr[i] = random_int(1, 1000);
	}
	print(arr, size);

	int result = peak(arr, 0, size - 1);
	printf("result: [%d]%d\n", result, arr[result]);

	bool correct = is_peak(arr, size, result);
	printf("correct: %s\n", correct ? "yes" : "no");

	return 0;
}

static int NOT_FOUND = -1;
int peak(int* arr, int head, int tail)
{
	int mid = (tail + head) / 2;
	printf("mid: %d, head: %d, tail: %d\n", mid, head, tail);
	if(mid + 1 <= tail && arr[mid] < arr[mid + 1])
		return peak(arr, mid + 1, tail);
	else if(mid - 1 >= head && arr[mid] < arr[mid - 1])
		return peak(arr, head, mid - 1);
	else
		return mid;
}

bool is_peak(int* arr, int size, int index)
{
	if(index > size - 1) return false;

	if(index == 0 && arr[index] >= arr[index + 1]) return true;
	if(index == size - 1 && arr[index] >= arr[index - 1]) return true;
	if(index > 0 && index < size - 1 && 
		arr[index] >= arr[index + 1] && 
		arr[index] >= arr[index - 1]) return true;

	return false;
}