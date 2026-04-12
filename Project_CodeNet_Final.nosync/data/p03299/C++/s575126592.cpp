#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int mod = 1000000007;
inline int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
int n, h[N];
pair<int, int> solve(int l, int r, int lim) {
	int mn = 0x3f3f3f3f, cntmn = 0;
	for (int i = l; i <= r; i++) {
		if (h[i] < mn) {
			mn = h[i];
			cntmn = 1;
		} else if (h[i] == mn) cntmn++;
	}
	pair<int, int> ret;
	if (cntmn == r - l + 1) {
		ret.first = (qp(2, r - l + 1) - 2 + mod) % mod;
		ret.second = qp(2, mn - lim - 1);
		return ret;
	}
	int t0 = 1, t1 = 1;
	for (int i = l, lst = l - 1; i <= r + 1; i++) {
		if (i > r || h[i] == mn) {
			if (lst < i - 1) {
				pair<int, int> cur = solve(lst + 1, i - 1, mn);
				t0 = 1ll * t0 * (cur.first + 4ll * cur.second % mod) % mod;
				t1 = 1ll * t1 * (2ll * cur.second % mod) % mod;
			}
			lst = i;
		}
	}
	t0 = (t0 - 2 * t1 % mod + mod) % mod;
	ret.first = 1ll * t0 * qp(2, cntmn) % mod;
	ret.first = (ret.first + 2ll * t1 * (qp(2, cntmn) - 1) % mod) % mod;
	ret.second = 1ll * t1 * qp(2, mn - lim - 1) % mod;
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
	pair<int, int> ret = solve(1, n, 0);
	int ans = (ret.first + 2ll * ret.second) % mod;
	printf("%d\n", ans);
	return 0;
}