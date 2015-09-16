#include <stdio.h>
#include <time.h>
#pragma warning(disable : 4996)

void hanoi_top(int numer, char start, char temp, char finish);
int main()
{

	int top_num=1;
	clock_t start,finish;
	double duration;
	

	
	while(top_num != 64)
	{
		start = clock();
		hanoi_top(top_num,'A','B','C');
		finish = clock();

		printf("\n");
		duration = ((double)(finish - start)/CLOCKS_PER_SEC);
		printf(" %d 층일떄 실행시간은 %.6f 초 입니다.\n",top_num,duration);

		top_num++;
	}
}
void hanoi_top(int number, char start, char temp, char finish)
{
	if(number == 1)
	{}
	else
	{
		hanoi_top(number-1,start,finish,temp);
		hanoi_top(number-1,temp,start,finish);
	}
}