#include <stdio.h>

int main()
{
	int i, x, y, N, rem, result;

	scanf("%d", &N);
	x = N * 800;
	rem = N / 15;
	y = rem * 200;
	result = x - y;
	printf("%d", result);
}
	
	