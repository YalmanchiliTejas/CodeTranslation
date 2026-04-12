#include<stdio.h>
int main()
{
	char A;
	char B;
	char C;
	scanf("%c %c %c", &A, &B, &C);
	
	if (A!=B || A!=C || B!=C)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}