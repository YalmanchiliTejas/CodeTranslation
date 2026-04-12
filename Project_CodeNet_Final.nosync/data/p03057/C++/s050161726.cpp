#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int n, m, dp[200005], sum[2][200005];
char s[200005];

int main() {
	scanf("%d%d%s", &n, &m, s + 1);
	if (count(s + 1, s + 1 + m, s[1]) == m) {
		if (n == 1) return puts("1"), 0;
		int ans = 0;
		for (int c = 0; c < 2; ++c) {
			int dp[2] = {};
			dp[c] = 1;
			for (int i = 2; i <= n; ++i) {
				int t = dp[1];
				dp[1] = dp[0];
				dp[0] = (dp[0] + t) % P;
			}
			ans = (ans + dp[0]) % P;
			if (!c) ans = (ans + dp[1]) % P;
		}
		printf("%d\n", ans);
		return 0;
	}
	int lim = n - 1;
	for (int i = 1, j; i <= m; i = j) {
		for (j = i; j <= m && s[j] == s[i]; ++j);
		if (j > m || s[i] != s[1]) continue;
		if (j - i & 1)
			lim = min(lim, j - i);
		else if (i == 1)
			lim = min(lim, j - i + 1);
	}
	dp[0] = 1;
	sum[0][0] = sum[0][1] = 1;
	sum[1][0] = sum[1][1] = 0;
	for (int i = 2; i <= n; ++i) {
		int d = max(0, i - lim - 1);
		dp[i] = (sum[i & 1][i - 2] - (d == 0 ? 0 : sum[i & 1][d - 1])) % P;
		sum[0][i] = sum[0][i - 1];
		sum[1][i] = sum[1][i - 1];
		sum[i & 1][i] = (sum[i & 1][i] + dp[i]) % P;
	}
	long long ans = 0;
	for (int i = 0; i <= lim; ++i)
		ans += sum[n & 1][n - (i + 1)] - (n == lim + 1 ? 0 : sum[n & 1][n - (lim + 1) - 1]);
	printf("%lld\n", (ans % P + P) % P);
	return 0;
}
