
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int X;
	scanf("%d", &X);
	if (X > 40 || X < -40)
	{
		printf("No");
	}
	else if (X >= 30)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
}