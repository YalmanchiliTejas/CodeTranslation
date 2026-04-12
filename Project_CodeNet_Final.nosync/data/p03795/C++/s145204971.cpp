

#include <stdio.h>

int main(void)
{
	int N;
	
	scanf("%d", &N);
	
	int x = N * 800;
	int y = N / 15 * 200;
	printf("%d\n", x - y);

	return 0;
}