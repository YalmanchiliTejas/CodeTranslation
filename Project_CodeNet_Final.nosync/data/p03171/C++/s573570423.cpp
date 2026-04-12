#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 3010;
int N, a[mxN];
ll dp[mxN][mxN][2];

ll rec(int l, int r, int t) {
	if (l > r) {
		return 0;
	}
	if (dp[l][r][t] != -1) {
		return dp[l][r][t];
	}
	if (t == 0) {
		return dp[l][r][t] = max(a[l] + rec(l + 1, r, 1), a[r] + rec(l, r - 1, 1));
	} else {
		return dp[l][r][t] = min(-a[l] + rec(l + 1, r, 0), -a[r] + rec(l, r - 1, 0));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	ll ans = rec(0, N -1, 0);
	cout << ans;
	
	return 0;
}
