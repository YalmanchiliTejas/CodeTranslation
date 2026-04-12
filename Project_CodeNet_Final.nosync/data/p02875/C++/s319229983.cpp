#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

#define MOD 998244353
int pow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = (int64_t) res * a % MOD;
		a = (int64_t) a * a % MOD;
	}
	return res;
}

int main() {
	static int fact[10000001];
	static int inv[10000001];
	fact[0] = 1;
	for (int i = 1; i <= 10000000; i++) fact[i] = (int64_t) fact[i - 1] * i % MOD;
	inv[10000000] = pow(fact[10000000], MOD - 2);
	for (int i = 10000000; i; i--) inv[i - 1] = (int64_t) inv[i] * i % MOD;
	
	int n;
	scanf("%d", &n);
	int res = pow(3, n);
	for (int i = n / 2 + 1; i <= n; i++) {
		res -= (int64_t) pow(2, n - i) * fact[n] % MOD * inv[i] % MOD * inv[n - i] * 2 % MOD;
		if (res < 0) res += MOD;
	}
	std::cout << res << std::endl;
	return 0;
}

