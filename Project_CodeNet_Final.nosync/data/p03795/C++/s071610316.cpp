#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N,n;
    int x,y;

    scanf("%d",&N);

    x = 8 * N;

    n = N - (N % 15);
    y = 2 * n/15;
    printf("%d00\n",(x-y));
	return 0;
}