#include <stdio.h>
#include <time.h>
#pragma warning(disable : 4996)

void hanoi_top(int numer, char start, char temp, char finish, int* count);
int main()
{

	int top_num;
	clock_t start, finish;
	double duration;
	int count = 0;

	printf("몇층의 탑인가요?");
	scanf("%d", &top_num);

	start = clock();
	hanoi_top(top_num, 'A', 'B', 'C', &count);
	finish = clock();

	printf("\n");

	duration = ((double)(finish - start) / CLOCKS_PER_SEC);
	printf("이동횟수는 %d 회 입니다 \n", count);
	printf("실행시간은 %.3f 초 입니다.\n", duration);

}
void hanoi_top(int number, char start, char temp, char finish, int* count)
{


	if (number == 1)
		printf("%c -> %c\t", start, finish);
	else
	{
		hanoi_top(number - 1, start, finish, temp, count);
		printf("%c -> %c\t", start, finish);
		hanoi_top(number - 1, temp, start, finish, count);
	}
	*count = *count + 1;
}
