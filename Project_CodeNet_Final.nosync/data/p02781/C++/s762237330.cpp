#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 4996)

#define N_MAX 100
#define K_MAX 3

// [k桁目][N以下確定?]
int DP[N_MAX][2][K_MAX+1];

int min(int a, int b) {
	if (a < b) return a;
	return b;
}

int main(void) {
	char N[N_MAX + 1];
	scanf("%s", &N[0]);
	int K;
	scanf("%d", &K);
	int len = strlen(N);
	{
		int d = N[0] - '0';
		for (int j = 0; j <= d; ++j) {
			bool lt = j < d;
			if (j != 0) {
				DP[0][lt ? 1 : 0][1] += 1;
			}
			else {
				DP[0][lt ? 1 : 0][0] += 1;
			}
		}
	}
	for (int i = 1; i < len; ++i) {
		int d = N[i] - '0';
		for (int lt = 0; lt < 2; ++lt) {
			for (int j = 0; j <= ((lt == 1) ? 9 : d); ++j) {
				bool nlt = (lt == 1) || (j < d);
				if (j != 0) {
					for (int c = 0; c < 3; ++c) {
						DP[i][nlt ? 1 : 0][c+1] += DP[i - 1][lt][c];
					}
				}
				else {
					for (int c = 0; c < 4; ++c) {
						DP[i][nlt ? 1 : 0][c] += DP[i - 1][lt][c];
					}
				}
			}
		}
	}
	printf("%d\n", DP[len-1][0][K]+ DP[len - 1][1][K]);
	return 0;
}
 