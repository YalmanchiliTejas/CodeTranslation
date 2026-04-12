#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)


int main(void) {
	int N;
	char S[10 + 1];
	int K;
	scanf("%d", &N);
	scanf("%s", &S[0]);
	scanf("%d", &K);

	char c = S[K - 1];
	for (int i = 0; i < N; ++i) {
		if (S[i] != c) {
			S[i] = '*';
		}
	}
	printf("%s", S);
	return 0;
}