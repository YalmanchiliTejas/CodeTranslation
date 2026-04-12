#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
using namespace std;
int n, a[3000];
long long dp[3000][3000][2];
bool vis[3000][3000][2];
long long calc(int l, int r, int t) {
	if (l > r) return 0;
	if (vis[l][r][t]) return dp[l][r][t];
	long long res;
	if (t == 0) {
		res = max(calc(l + 1, r, 1) + a[l], calc(l, r - 1, 1) + a[r]);
	} else {
		res = min(calc(l + 1, r, 0) - a[l], calc(l, r - 1, 0) - a[r]);
	}
	vis[l][r][t] = 1;
	return dp[l][r][t] = res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	memset(vis, 0, sizeof(vis));
	long long ans = calc(0, n - 1, 0);
	printf("%lld\n", ans);
	return 0;
}