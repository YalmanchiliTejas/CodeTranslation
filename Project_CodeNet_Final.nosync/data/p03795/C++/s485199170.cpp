#include <stdio.h>
int main() {
	int ans = 0,N;
	scanf("%d", &N);
	printf("%d", N * 800 - 200 * (N / 15));
	return 0;
}