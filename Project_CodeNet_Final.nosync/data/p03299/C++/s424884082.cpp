#include <bits/stdc++.h>
using namespace std;

const int maxn = 100, mod = 1e9 + 7;
int n, a[maxn + 3];

int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % mod) {
		if (b & 1) c = 1ll * a * c % mod;
	}
	return c;
}

pair<int, int> solve(int l, int r, int h) {
	if (l == r) {
		int x = qpow(2, a[l] - h);
		return make_pair(x, x);
	}
	int mn = a[l];
	for (int i = l; i <= r; i++) {
		mn = min(mn, a[i]);
	}
	int c = 1, t = qpow(2, mn - h);
	for (int i = l; i <= r; i++) {
		if (a[i] == mn) c = 2ll * c % mod;
	}
	int x = 1, y = 1;
	for (int i = l, j = l; i <= r; i = j + 1, j = i) {
		if (a[i] == mn) continue;
		while (j < r && a[j + 1] != mn) j++;
		pair<int, int> t = solve(i, j, mn);
		x = 1ll * x * (t.first + t.second) % mod;
		y = 1ll * y * t.first % mod;
	}
	int p = 1ll * t * y % mod;
	int q = (1ll * c * x + 1ll * (t + mod - 2) * y) % mod;
	return make_pair(p, q);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", solve(1, n, 0).second);
	return 0;
}