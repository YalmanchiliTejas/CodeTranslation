#include <stdio.h>

#pragma warning(disable:4996)

int main(void) {
	int N;
	int H[20];
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &H[i]);
	}
	int sum = 0;
	int max = -1;
	for (int i = 0; i < N; ++i) {
		if (H[i] >= max) {
			++sum;
			max = H[i];
		}
	}

	printf("%d", sum);

	return 0;
}