#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int N, A, B, C, D;
int dp[1005][1005], c[1005][1005], f[1000005], gc[1005][1005];

int qexp(int b, int p, int m) {
	if (p == 1) return b % m;
	if (p == 0) return 1 % m;
	if (p % 2 == 0) {
		int sub = qexp(b, p/2, m);
		return ((long long)sub * sub) % m;
	} else {
		long long sub = qexp(b, p/2, m);
		sub *= sub;
		sub %= m;
		sub *= b;
		return sub % m;
	}
}

int mod_inv(int x) {
	return qexp(x, MOD - 2, MOD);
}

int choose(int n, int k) {
	if (k < 0) return 0;
	if (k > n) return 0;
	if (n == 0) return 1;
	if (n == 1) return 1;
	if (c[n][k] != -1) return c[n][k];
	return c[n][k] = (choose(n - 1, k) + choose(n -1, k-1)) % MOD;
}

int main() {
	long long cur = 1;
	f[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		cur *= i;
		cur %= MOD;
		f[i] = cur;
	}
	
	memset(c, -1, sizeof(c));
	scanf("%d%d%d%d%d", &N, &A, &B, &C, &D);
	for (int i = 1; i <= N; i++) {
		long long denom = 1;
		for (int k = 0; k <= N/i; k++) {
			gc[k][i] = ((long long)f[k * i] * mod_inv(denom)) % MOD;
			gc[k][i] = ((long long)mod_inv(f[k]) * gc[k][i]) % MOD;
			//gc[k][i] %= MOD;
			denom *= f[i];
			denom %= MOD;
			//printf("%d %d = %d\n", k, i, gc[k][i]);
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			long long cc = 1;
			// i - group size considering, j - current number
			for (int k = 0; k <= j/i; k++) {
				if (!(k == 0 || (i >= A && i <= B && k >= C && k <= D))) continue;
				long long cur = ((long long)dp[i - 1][j - k * i] * choose(N - (j - k * i), k * i)) % MOD;
				cur *= gc[k][i];
				cur %= MOD;
				dp[i][j] += cur;
				
				dp[i][j] %= MOD;
				
			}
			//printf("%d %d = %d\n", i,j,dp[i][j]);
		}
	}
	printf("%d\n", dp[N][N]);
}
