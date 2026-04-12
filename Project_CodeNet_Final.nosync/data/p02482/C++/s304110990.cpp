#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);

	if (a < b){
		printf("a < b\n");
	}

	if (a>b){
		printf("a > b\n");
	}

	if (a == b){
		printf("a == b\n");
	}

	return 0;
}