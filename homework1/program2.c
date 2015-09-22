#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#pragma warning(disable : 4996)

enum{ MAXSIZE = 100000 };
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void sort(int list[], int n);
void Arr_allocate(int list[], int n);
void Arr_print(int list[], int n);
int main()
{

	int number = 1000;
	int sort_Arr[MAXSIZE];
	clock_t start, stop;
	double duration;
	FILE* fp = fopen("result.txt", "w");



	do
	{
		Arr_allocate(sort_Arr, number);
		start = clock();
		sort(sort_Arr, number);
		stop = clock();

		duration = ((double)(stop - start)) / CLOCKS_PER_SEC;

		fprintf(fp, "number =%d time = %.3f\n", number, duration);

		printf("%d 완료..\n", number);
		number = number + 10000;

	} while (number < 100000);


	fclose(fp);
	printf("sorting 완료! \n");
	return 0;
}
void Arr_allocate(int sort_Arr[], int number)
{
	int for_i;

	for (for_i = 0; for_i < number; for_i++)
	{
		sort_Arr[for_i] = rand() % 1000;
	}
}
void sort(int list[], int n)
{

	int i, j, min, temp;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}