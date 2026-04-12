#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n, mod;
int pw1[N * N], pw2[N * N], C[N][N];
int stirling[N][N];
int res[N];

void add(int &x, int y) {
	x += y; while(x >= mod) x -= mod; while(x < 0) x += mod;
}

int binpow(int a, int b) {
	int ret = 1;
	while(b) {
		if (b & 1) ret = 1LL * ret * a % mod; a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> mod;

	// prepare
	pw1[0] = pw2[0] = 1;
	for (int i = 1; i < N * N; ++i) {
		pw1[i] = 2LL * pw1[i - 1] % mod;
		pw2[i] = 2LL * pw2[i - 1] % (mod - 1);
	}
	for (int i = 0; i < N; ++i) C[i][0] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}

	stirling[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			stirling[i][j] = (1LL * (j + 1) * stirling[i - 1][j] + (j > 0 ? stirling[i - 1][j - 1] : 0)) % mod;
		}
	}

	// solve
	for (int k = 0; k <= n; ++k) {
		for (int i = 0; i <= k; ++i) {
			add(res[k], 1LL * stirling[k][i] * pw1[(n - k) * i] % mod);
		}
		res[k] = 1LL * res[k] * binpow(2, pw2[n - k]) % mod;
	}

	// inclusive-exclusive
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		int cur = 1LL * res[i] * C[n][i] % mod;
		if (i % 2 == 0) add(ans, cur);
		else add(ans, -cur);
	}
	cout << ans << '\n';
}