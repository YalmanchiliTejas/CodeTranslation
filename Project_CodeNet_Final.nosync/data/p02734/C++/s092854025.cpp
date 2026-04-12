#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,mmx,abm")
#pragma GCC optimize("unroll-loops,inline")
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 3010;
int n, s;
int a[MAXN];
int dp[MAXN];

signed main() {
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 0; i <= s; i++)
		dp[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int w = s - a[i]; w >= 1; w--) {
			dp[w + a[i]] += dp[w];
			dp[w + a[i]] -= MOD * (dp[w + a[i]] >= MOD);
		}
		dp[a[i]] += i;
		dp[a[i]] -= MOD * (dp[a[i]] >= MOD);
		ans += dp[s];
		ans -= MOD * (ans >= MOD);
	}
	printf("%d\n", ans);
	return 0;
}