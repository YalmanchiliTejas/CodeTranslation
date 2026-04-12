#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct ModCombination {
	vector<ll> inv;
	vector<ll> fac;
	vector<ll> ifac;
	ll MOD;

	ModCombination(const size_t Size, const ll mod) {
		MOD = mod;
		inv.assign(Size, 0);
		fac.assign(Size, 0);
		ifac.assign(Size, 0);
		inv[0] = inv[1] = 1;
		fac[0] = fac[1] = 1;
		ifac[0] = ifac[1] = 1;
		for (int i = 2; i < Size; ++i) {
			inv[i] = ((-MOD / i) * inv[MOD % i]) % MOD;
			fac[i] = (fac[i - 1] * i) % MOD;
			ifac[i] = (ifac[i - 1] * inv[i]) % MOD;
		}
	}
	
	ll nCr(int n, int r) {
		return (((fac[n] * ifac[r]) % MOD) * ifac[n - r]) % MOD;
	}
};

int main() {
	const ll MOD = 1e9 + 7;
	ll N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	ModCombination Comb(N + 1, MOD);
	vector<vector<ll>> dp(B + 1, vector<ll>(N + 1, 0));
	dp[A - 1][0] = 1;
	for (int i = A; i <= B; ++i) {
		for (int j = 0; j <= N; ++j) {
			if (dp[i - 1][j] == 0) { continue; }
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;

			ll tmp = 1;
			for (int k = 1; (k <= D) && (j + i*k <= N); ++k) {
				int n = N - j - i*(k - 1);
				tmp = (((tmp * Comb.nCr(n, i)) % MOD) * Comb.inv[k]) % MOD;
				if (k >= C) {
					dp[i][j + i*k] = (dp[i][j + i*k] + dp[i - 1][j]*tmp + MOD) % MOD;
				}
			}
		}
	}

	ll res = (dp[B][N] + MOD) % MOD;
	cout << res << endl;

	return 0;
}
