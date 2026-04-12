#include <cstdio>
#include <algorithm>
using namespace std;
int a[3010], n;
long long dp[3010][3010];
long long go(int l, int r) {
	if (l >= r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	long long &res = dp[l][r];
	int x = (r - l) ^ n;
	if (x & 1) {
		res = min(go(l + 1, r) - a[l], go(l, r - 1) - a[r-1]);
	} else {
		res = max(go(l + 1, r) + a[l], go(l, r - 1) + a[r-1]);
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	printf("%lld\n", go(0, n));
	return 0;
}
