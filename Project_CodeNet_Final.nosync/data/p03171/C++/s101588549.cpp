#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3003, mod = 1e9 + 7;

int n, a[N], dp[2][N][N];

int solve(int l, int r, bool p) {
	if (l > r) {
		if (!p) return 0;
		return INT_MAX;
	}
	if (dp[p][l][r]) return dp[p][l][r];
	if (l == r) {
		if (!p) return a[l];
		else return -a[r];
	}
	if (!p) return dp[p][l][r] = max(a[l] + solve(l + 1, r, 1), a[r] + solve(l, r - 1, 1));
	return dp[p][l][r] = min(solve(l + 1, r, 0) - a[l], solve(l, r - 1, 0) - a[r]);
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << solve(1, n, 0);
}