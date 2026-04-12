#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 3005;

int n, mod;
int C[Maxn][Maxn];
int pw2[Maxn], all[Maxn];
int dp[Maxn][Maxn];
int cnt[Maxn];
int my[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &mod);
	for (int i = 0; i <= n; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	pw2[0] = 1 % mod;
	all[0] = 2 % mod;
	for (int i = 1; i <= n; i++) {
		pw2[i] = ll(pw2[i - 1]) * 2 % mod;
		all[i] = ll(all[i - 1]) * all[i - 1] % mod;
	}
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++) if (dp[i][j]) {
			dp[i + 1][j] = (dp[i + 1][j] + ll(dp[i][j]) * (j + 1)) % mod;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
		}
	for (int i = n; i >= 0; i--) {
		int tot = 0;
		int cur = 1;
		for (int j = 0; j <= i; j++) {
			tot = (tot + ll(dp[i][j]) * cur) % mod;
			cur = ll(cur) * pw2[n - i] % mod;
		}
		tot = ll(tot) * all[n - i] % mod * C[n][i] % mod;
		if (i % 2 == 0) res = (res + tot) % mod;
		else res = (res - tot + mod) % mod;
	}
	printf("%d\n", res);
	return 0;
}