#include <cstdio>

#define N 6

int main() {
	char S[N] = {0};
	scanf("%s", S);

	for (int i = 0; i < N - 1; i++) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	
}
