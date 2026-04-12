#include<stdio.h>
int main()
{
	int N, a;
	scanf("%d", &N);
	
	a = (N - N % 15) / 15;
	
	printf("%d", 800*N-200*a);
	
	return 0;
	
}