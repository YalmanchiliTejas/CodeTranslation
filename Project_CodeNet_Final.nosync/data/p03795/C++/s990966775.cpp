#include <stdio.h>

int N;
int ans;

int main(void)
{
	scanf("%d", &N);
	
	ans = 800 * N;
	ans -= 200 * (N / 15);

	printf("%d\n", ans);
	return 0;
}