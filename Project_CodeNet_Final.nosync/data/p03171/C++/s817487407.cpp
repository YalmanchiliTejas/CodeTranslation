#include <iostream>
#include <assert.h>

using namespace std;
typedef long long ll;

int n;
ll t[3005], st[3005];

ll dp[3005][3005];

ll gsum(int l, int r) {
	return st[r]-st[l-1];
}

ll solve(int l, int r, int cp) {
	assert(l <= r);
	assert(cp == 0 || cp == 1);

	if (l == r) return t[l];
	if (dp[l][r] != -1) return dp[l][r];

	ll lres = t[l] + (gsum(l+1, r) - solve(l+1, r, cp^1));
	ll rres = t[r] + (gsum(l, r-1) - solve(l, r-1, cp^1));

	return dp[l][r] = max(lres, rres);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	ll tsum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		st[i] = st[i-1]+t[i];
		tsum += t[i];
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = -1;
		}
	}
	ll ares = solve(1, n, 0);
	cout << (ares - (tsum-ares)) << "\n";
	return 0;
}

/*
	solve(l, r, cp) = max sum that player cp can get when ends are at (l, r)

	if l == r, return t[l]
	otherwise take the one
*/
