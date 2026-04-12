#include <stdio.h>
int main(void)
{
	int N = 0;
	int H[101];
	int count = 0;
	int max = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &H[i]);
	}

	for (int i = 0; i < N; i++) {
		if (H[i] >= max) {
			count++;
			max = H[i];
		}
	}
	printf("%d", count);
	return 0;
}

