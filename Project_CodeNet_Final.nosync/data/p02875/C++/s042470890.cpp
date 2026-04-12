#ifdef LOCAL_EXEC
#include "include.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define trace(...)
#endif

using LL = long long;

const LL MOD = 998244353;

LL modpow(LL a, LL n) {
	LL res = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
	}
	return res;
}

const int N = 1e7 + 1;
LL fact[N], inv[N];
LL choose(int n, int r) {
	return (fact[n] * ((inv[r] * inv[n - r]) % MOD)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv[i] = modpow(fact[i], MOD - 2);
	}

	int n; cin >> n;
	LL rem = 0;
	for (int i = n / 2 + 1; i <= n; i++) {
		rem += (choose(n, i) * modpow(2, n - i + 1)) % MOD;
	}
	LL ans = (modpow(3, n) + MOD - (rem % MOD)) % MOD;
	cout << ans << endl;

	return 0;
}
