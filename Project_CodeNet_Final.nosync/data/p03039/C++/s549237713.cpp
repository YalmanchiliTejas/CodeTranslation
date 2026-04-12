#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll Sum(ll n) { return (n * (n + 1) / 2) % 1000000007; }

struct ModComb {
	vector<long long> fac;
	vector<long long> ifac;
	const long long MOD = 1000000007;

	template <typename T>
	T power(T a, T b) {
		T ret = 1;
		while (b > 0) {
			if (b&1) { (ret *= a) %= MOD; }
			(a *= a) %= MOD;
			b >>= 1;
		}
		return ret;
	}

	ModComb(const size_t SIZE) {
		fac.assign(SIZE, 0);
		ifac.assign(SIZE, 0);

		fac[0] = ifac[0] = 1;
		for (int i = 1; i < SIZE; ++i) {
			fac[i] = (fac[i - 1] * i) % MOD;
			ifac[i] = power(fac[i], MOD - 2) % MOD;
		}
	}

	long long nCr(size_t n, size_t r) {
		return (((fac[n] * ifac[r]) % MOD) * ifac[n - r]) % MOD;
	}
};

int main() {
	const ll MOD = 1e9 + 7;
	ll N, M, K;
	cin >> N >> M >> K;

	ModComb comb(N * M + 1);
	ll C, res = 0;
	if (N * M == 2 || K == 2) { C = 1; }
	else { C = comb.nCr(N * M - 2, K - 2); }
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ll cost = (Sum(N - i - 1) * M + Sum(j) * (N - i - 1) + Sum(M - j - 1) * (N - i)) % MOD;
			(res += (cost * C) % MOD) %= MOD;
		}
	}

	cout << res % MOD << endl;

	return 0;
}
