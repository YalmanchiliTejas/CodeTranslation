#include <bits/stdc++.h>

using namespace std;

#define li long long int

const int N 	= 3e3 + 3;
const int mod 	= 1e9 + 7;

int n;
int a[N];
li dp[N][N][2];

li go(int l, int r, int turn) {
	if (l > r) return 0;
	if (dp[l][r][turn] != -1) return dp[l][r][turn];
	li ans;
	if (turn == 0) {
		ans = -4e12;
		ans = max(ans, a[l] + go(l + 1, r, 1));
		ans = max(ans, a[r] + go(l, r - 1, 1));
	} else {
		ans = 4e12;
		ans = min(ans, -a[l] + go(l + 1, r, 0));
		ans = min(ans, -a[r] + go(l, r - 1, 0));
	}
	return dp[l][r][turn] = ans;
} 

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	li ans = go(1, n, 0);
	cout << ans;
} 

int main() {
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}