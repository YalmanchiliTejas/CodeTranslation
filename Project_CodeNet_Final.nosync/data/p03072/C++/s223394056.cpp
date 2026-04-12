#include <stdio.h>

int main(void)
{
	int i, N, temp, count = 1, H[100];
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}

	temp = H[0];
	for (i = 1; i < N; i++) {
		if (temp <= H[i]) {
			count++;
			temp = H[i];
		}
	}

	printf("%d", count);

	return 0;
}