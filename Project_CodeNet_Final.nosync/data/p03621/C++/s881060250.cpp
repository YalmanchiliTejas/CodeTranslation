#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;

ll pw(ll a, ll b) {
	ll ans = 1;
	while (b) {
		while (!(b & 1))
			b >>= 1, a = (a * a) % MOD;
		--b;
		ans = (ans * a) % MOD;
	}
	return ans;
}

string s, t;
const int MX = 51000;
const ll B = 646;

int a, b;
ll fc[MX];
ll bfc[MX];

int rev(int x, int k) {
	int ans = 0;
	for (int i = 0; i < k; ++i) {
		ans = ans * 2 + (x & 1);
		x >>= 1;
	}
	return ans;
}

void fft(ll *a, int k, int inv) {
	int n = (1 << k);
	for (int i = 0; i < n; ++i) {
		int x = rev(i, k);
		if (x > i)
			swap(a[x], a[i]);
	}
	for (int bl = 1; bl < n; bl *= 2) {
		ll wadd = pw(B, (1 << 20) / (bl * 2));
		if (inv)
			wadd = pw(wadd, MOD - 2);
		for (int i = 0; i < n; i += 2 * bl) {
			ll w = 1;
			for (int j = i; j < i + bl; ++j, w = (w * wadd) % MOD) {
				ll u = a[j];
				ll v = a[j + bl] * w % MOD;
				a[j] = (u + v) % MOD;
				a[j + bl] = (u - v + MOD) % MOD;
			}
		}
	}
	if (inv) {
		ll n2 = pw(n, MOD - 2);
		for (int i = 0; i < n; ++i)
			a[i] = (a[i] * n2) % MOD;
	}
}

void add(ll &a, ll b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
}
ll gg[40000];
ll ans[40000];

int main() {
	fc[0] = 1;
	bfc[0] = 1;
	for (int i = 1; i < MX; ++i) {
		fc[i] = (fc[i - 1] * i) % MOD;
		bfc[i] = pw(fc[i], MOD - 2);
	}
	cin >> s >> t;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '1') {
			if (t[i] == '1')
				++b;
			else
				++a;
		}
	}
	for (int k = 0; k <= b; ++k)
		gg[k] = bfc[k + 1];
	ans[0] = 1;
	int p = a;
	int sh = 0;
	while ((1 << sh) <= 2 * b)
		++sh;
	while (p) {
		while (!(p & 1)) {
			p >>= 1;
			fft(gg, sh, 0);
			for (int i = 0; i < (1 << sh); ++i)
				gg[i] = (gg[i] * gg[i]) % MOD;
			fft(gg, sh, 1);
			for (int i = b + 1; i < (1 << sh); ++i)
				gg[i] = 0;
		}
		--p;
		fft(gg, sh, 0);
		fft(ans, sh, 0);
		for (int i = 0; i < (1 << sh); ++i)
			ans[i] = (ans[i] * gg[i]) % MOD;
		fft(gg, sh, 1);
		fft(ans, sh, 1);
		for (int i = b + 1; i < (1 << sh); ++i)
			ans[i] = 0;
	}
	/*
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j <= b; ++j) {
			for (int k = 0; k + j <= b; ++k) {
				add(dp[i + 1][k + j], dp[i][j] * fc[b - j] % MOD * bfc[b - j - k] % MOD * bfc[k + 1] % MOD);
			}
		}
	}*/
	ll ans2 = 0;
	for (int i = 0; i <= b; ++i) {
		add(ans2, ans[i] * fc[b - i] % MOD * fc[b] % MOD * bfc[b - i] % MOD);
	}
	ans2 = (ans2 * fc[a] % MOD * fc[a + b]) % MOD;
	cout << ans2 << "\n";
	return 0;
}


