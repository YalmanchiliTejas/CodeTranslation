#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100, MOD = 1000 * 1000 * 1000 + 7;

int sum(int a, int b) {
	a += b;
	if(a < 0)
		a += MOD;
	else if(a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b) {
	return 1LL * a * b % MOD;
}

int n, m, k, s, ans, fac[N], inv[N];

void pre_pro() {
	inv[1] = 1;
	for (int i = 2; i < N; i++)
		inv[i] = mul(MOD - MOD / i, inv[MOD % i]);
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; i++) {
		inv[i] = mul(inv[i], inv[i - 1]);
		fac[i] = mul(fac[i - 1], i);
	}
}

int c(int a, int b) {
	return (a > b? 0: mul(fac[b], mul(inv[a], inv[b - a])));
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	pre_pro();
	cin >> n >> m >> k;
	for (int i = 1; i < m; i++)
		s = sum(s, mul(mul(m - i, i), mul(n, n)));
	for (int i = 1; i < n; i++)
		s = sum(s, mul(mul(n - i, i), mul(m, m)));
	cout << mul(s, c(k - 2, n * m - 2));
	return 0;
}