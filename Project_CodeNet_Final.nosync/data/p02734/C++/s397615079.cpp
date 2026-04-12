#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,mmx,abm")
#pragma GCC optimize("unroll-loops,inline")
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

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
			dp[w + a[i]] = add(dp[w + a[i]], dp[w]);
		}
		dp[a[i]] = add(dp[a[i]], i);
		ans = add(ans, dp[s]);
	}
	printf("%d\n", ans);
	return 0;
}