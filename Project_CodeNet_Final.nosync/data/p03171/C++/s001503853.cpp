#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N = (int)3e3 + 7;
const ll inf = (ll)1e18 + 7;

ll dp[2][N][N];
ll a[N];
int n;

ll calc(int tp, int l, int r) {
	if (l > r) return 0;
	ll &res = dp[tp][l][r];
	if (res != -1) return res;
	res = 0;
	if (tp == 0) {
		res = -inf;
		res = max(res, calc(tp ^ 1, l + 1, r) + a[l]);
		res = max(res, calc(tp ^ 1, l, r - 1) + a[r]);
	} else {
		res = inf;
		res = min(res, calc(tp ^ 1, l + 1, r) - a[l]);
		res = min(res, calc(tp ^ 1, l ,r - 1) - a[r]);
	}
	return res;
}

main() {
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	cout << calc(0, 1, n);
}
