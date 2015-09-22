#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

#pragma warning(disable : 4996)

enum{ MAXSIZE = 1000 };
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

void sort(int list[], int n);
void Arr_allocate(int list[], int n);
void Arr_print(int list[], int n);
int main()
{
	int for_i;
	int number;
	int sort_Arr[MAXSIZE];


	do
	{
		printf("생성할 배열의 크기를 입력하시요 : ");
		scanf("%d", &number);


		Arr_allocate(sort_Arr, number);
		sort(sort_Arr, number);
		Arr_print(sort_Arr, number);

		printf(" 재시작[Anykey] 종료[space]\n");
	} while (getch() != ' ');

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
void Arr_print(int list[], int n)
{
	int for_i;

	for (for_i = 0; for_i < n; for_i++)
	{
		printf("%5d", list[for_i]);
		if (for_i % 10 == 9)
			printf("\n");
	}
	printf("\n");
}