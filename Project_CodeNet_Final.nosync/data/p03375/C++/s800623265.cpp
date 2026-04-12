#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int n, mod;
int f[N][N];
int c[N][N];

void add(int &x, int y) { x = (x + y) >= mod ? x + y - mod : x + y; }

int main() {
	cin >> n >> mod;
	f[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			add(f[i + 1][j], f[i][j]);
			add(f[i + 1][j], 1LL * f[i][j] * j % mod);
			add(f[i + 1][j + 1], f[i][j]);
		}
	}
	for (int i = 0; i <= n; ++i) c[i][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
	int res = 0;
	for (int i = 0; i <= n; ++i) {
		int m = n - i;
		int v0 = 1, v1 = 2;
		for (int j = 0; j < m; ++j) v0 = 2LL * v0 % mod; // 2 ^ m
		for (int j = 0; j < m; ++j) v1 = 1LL * v1 * v1 % mod; // 2 ^ (2 ^ m)
		int sum = 0, cur = 1;
		for (int j = 0; j <= i; ++j) {
			add(sum, 1LL * cur * f[i][j] % mod * v1 % mod), cur = 1LL * cur * v0 % mod;
		}
		sum = 1LL * sum * c[n][i] % mod;
		// cout << sum << '\n';
		if (i & 1) res -= sum; else res += sum;
		if (res >= mod) res -= mod; if (res < 0) res += mod;
	}
	cout << res;
}