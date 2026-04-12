#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Combination {
    vector<int64_t> fact, rfact;
	const int64_t MOD = 1000000007;

    Combination(int sz) : fact(sz + 1), rfact(sz + 1) {
        fact[0] = 1;
        for(int i = 1; i < fact.size(); i++){
            fact[i] = fact[i - 1] * i % MOD;
        }
        rfact[sz] = inv(fact[sz]);
        for(int i = sz - 1; i >= 0; i--){
            rfact[i] = rfact[i + 1] * (i + 1) % MOD;
        }
    }
    int64_t inv(int x) const {
        return pow(x, MOD - 2);
    }
    int64_t pow(int64_t x, int64_t n) const {
        int64_t ret = 1;
        while (n > 0) {
            if (n & 1) { (ret *= x) %= MOD; }
            (x *= x) %= MOD;
            n >>= 1;
        }
        return (ret);
    }

    int64_t P(int n, int r) const {
        if (r < 0 || n < r) { return 0; }
        return (fact[n] * rfact[n - r] % MOD);
    }

    int64_t C(int p, int q) const {
        if (q < 0 || p < q) { return 0; }
        return (fact[p] * rfact[q] % MOD * rfact[p - q] % MOD);
    }

    int64_t H(int n, int r) const {
        if (n < 0 || r < 0) { return 0; }
        return (r == 0 ? 1 : C(n + r - 1, r));
    }
};

ll calc(ll n) { return (n * (n + 1) / 2) % 1000000007; }

int main() {
	const ll MOD = 1e9 + 7;
	ll N, M, K;
	cin >> N >> M >> K;

	Combination comb(N * M);
	ll res = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ll cost = (calc(N - i - 1) * M + calc(j) * (N - i - 1) + calc(M - j - 1) * (N - i)) % MOD;
			(res += (cost * comb.C(N * M - 2, K - 2)) % MOD) %= MOD;
		}
	}
	cout << res % MOD << endl;

	return 0;
}
