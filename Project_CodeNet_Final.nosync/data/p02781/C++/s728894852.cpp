#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)

ll N, K, i, j, k;
ll dp[111][5][2];
int main(void) {
	char str[200];
	scanf("%s", str);
	N = strlen(str);
	scanf("%d", &K);
	dp[0][0][1] = 1;
	for (i = 0; i < N; i++) {
		for (j = 0; j <= K; j++) {

			for (k = 0; k < 10; k++) {
				dp[i + 1][j + (k != 0)][0] += dp[i][j][0];
			}

			ll MX = str[i] - '0';
			for (k = 0; k < MX; k++) {
				dp[i + 1][j + (k != 0)][0] += dp[i][j][1];
			}

			dp[i + 1][j + (MX != 0)][1] += dp[i][j][1];
		}
	}

	printf("%d",dp[N][K][0] + dp[N][K][1]);
}