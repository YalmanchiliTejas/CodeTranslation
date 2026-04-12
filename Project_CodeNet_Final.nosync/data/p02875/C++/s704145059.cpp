#include <bits/stdc++.h>
#define maxn 10000005
#define mod 998244353
using namespace std;

long long fact[maxn], inv[maxn], p2[maxn];
int n;

long long get_power(int x, int p) {
	if (!p) {
		return 1;
	}
	long long q = get_power(x, p/2);
	q = (q * q) % mod;
	if (p & 1) {
		q = (q * x) % mod;
	}
	return q;
}

long long binom(int x, int y) {
	if (x < y) {
		return 0;
	}
	long long up = fact[x], down = (inv[y] * inv[x - y]) % mod;
	return up * down % mod;
}

int main() {
	scanf("%d", &n);
	long long ways = get_power(3, n);
	long long exc = 0;

	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	inv[n] = get_power(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % mod;
	}

	p2[0] = 1;
	for (int i = 1; i <= n; i++) {
		p2[i] = (p2[i - 1] * 2) % mod;
	}

	for (int i = n/2 + 1; i <= n; i++) {
		exc = (exc + binom(n, i) * p2[n - i]) % mod;
	}
	exc = (exc * 2) % mod;

	cout << (ways + mod - exc) % mod << endl;
}