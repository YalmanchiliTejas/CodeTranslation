#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;
const LL MOD = 1000000007LL;
LL comb[1001][1001];
LL inv_fact[1001];
LL dp[1001][1001];
LL mod_pow(LL a, LL n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		LL b = mod_pow(a, n / 2);
		return (b*b) % MOD;
	}
	return (a*mod_pow(a, n - 1)) % MOD;
}
int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	comb[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < N; j++) {
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}
	inv_fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		inv_fact[i] = inv_fact[i - 1];
		(inv_fact[i] *= mod_pow(i, MOD - 2)) %= MOD;
	}
	dp[A - 1][0] = 1;
	for (int k = A; k <= B; k++) {
		for (int n = 0; n <= N; n++) {
			LL y = 1;
			for (int x = 0; x <= n / k; x++) {
				if (x > 0) (y *= comb[n - k*(x - 1)][k]) %= MOD;
				if (x == 0 || (C <= x && x <= D)) {
					LL add = y;
					(add *= dp[k - 1][n - k*x]) %= MOD;
					(add *= inv_fact[x]) %= MOD;
					(dp[k][n] += add) %= MOD;
				}
			}
		}
	}
	cout << dp[B][N] << endl;
}