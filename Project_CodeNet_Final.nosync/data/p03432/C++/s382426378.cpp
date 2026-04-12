#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353, proot = 3;

int n, m, ans;
vector<int> fac, ifac, dp, f;

int pow_mod(int x, int n) {
	int y = 1;
	while(n) {
		if(n & 1) {
			y = (long long) y * x % mod;
		}
		x = (long long) x * x % mod;
		n >>= 1;
	}
	return y;
}

int inv(int x) {
	return pow_mod(x, mod - 2);
}

int C(int n, int m) {
	return m < 0 || n < m ? 0 : (long long) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void prepare() {
	fac.resize(n + 3);
	ifac.resize(n + 3);
	fac[0] = 1;
	for (int i = 1; i <= n + 2; ++i) {
		fac[i] = (long long) fac[i - 1] * i % mod;
	}
	ifac[n + 2] = inv(fac[n + 2]);
	for (int i = n + 2; i; --i) {
		ifac[i - 1] = (long long) ifac[i] * i % mod;
	}
	return;
}

int lowbit(int x) {
	return x & (-x);
}

int getpw2(int x) {
	while(x != lowbit(x)) {
		x += lowbit(x);
	}
	return x;
}

void dft(vector<int> &a, bool rev) {
	int n = a.size();
	for (int i = 0, j = 0; i < n; ++i) {
		if(i < j) {
			swap(a[i], a[j]);
		}
		for (int k = n >> 1; (j ^= k) < k; k >>= 1);
	}
	vector<int> w(n, 0);
	w[0] = 1;
	for (int hl = 1, l = 2; l <= n; hl = l, l <<= 1) {
		int wn = pow_mod(proot, (mod - 1) / l);
		if(rev) {
			wn = inv(wn);
		}
		for (register int i = hl - 1; ~i; --i) {
			w[i << 1] = w[i];
			w[(i << 1) | 1] = (long long) w[i] * wn % mod;
		}
		for (int i = 0; i < n; i += l) {
			for (register int j = 0, x; j < hl; ++j) {
				int &t = a[i + hl + j];
				x = (long long) w[j] * t % mod;
				t = (a[i + j] - x) % mod;
				a[i + j] = (a[i + j] + x) % mod;
			}
		}
	}
	if(rev) {
		int inv_n = inv(n);
		for (int i = 0; i < n; ++i) {
			a[i] = (long long) inv_n * a[i] % mod;
		}
	}
	return;
}

void mul(vector<int> &a, vector<int> &b, vector<int> &c) {
	int M = a.size() + b.size() - 1, N = getpw2(M);
	vector<int> A(N, 0), B(N, 0);
	for (int i = 0; i < a.size(); ++i) {
		A[i] = a[i];
	}
	for (int i = 0; i < b.size(); ++i) {
		B[i] = b[i];
	}
	dft(A, 0);
	dft(B, 0);
	for (int i = 0; i < N; ++i) {
		A[i] = (long long) A[i] * B[i] % mod;
	}
	dft(A, 1);
	c.clear();
	for (int i = 0; i < M; ++i) {
		c.push_back(A[i] < 0 ? A[i] + mod : A[i]);
	}
	return;
}

void transfer() {
	vector<int> g(n + 1, 0);
	for (int i = 0; i <= n; ++i) {
		g[i] = (long long) dp[i] * ifac[i] % mod;
	}
	mul(f, g, g);
	for (int i = 0; i <= n; ++i) {
		dp[i] = ((long long) dp[i] * (C(i + 1, 2) + 1) + (long long) g[i] * fac[i + 2]) % mod;
	}
	return;
}

int main() {
	cin >> n >> m;
	prepare();
	dp.assign(n + 1, 1);
	f.assign(ifac.begin() + 2, ifac.end());
	f[0] = 0;
	for (int i = 2; i <= m; ++i) {
		transfer();
	}
	for (int i = 0; i <= n; ++i) {
		ans = ((long long) dp[i] * C(n, i) + ans) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
