#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;
const LL MOD = 1000000007LL;
LL mod_pow(LL a, LL n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		LL t = mod_pow(a, n / 2);
		return (t*t) % MOD;
	}
	return (a*mod_pow(a, n - 1)) % MOD;
}
LL inv[1001];
LL dp[1001][1001];
LL comb[1001][1001];
int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	comb[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j];
			(comb[i][j] += comb[i - 1][j - 1]) %= MOD;
		}
	}
	inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		inv[i] = inv[i - 1];
		(inv[i] *= mod_pow(i, MOD - 2)) %= MOD;
	}
	dp[A - 1][0] = 1;
	for (int k = A; k <= B; k++) {
		for (int n = 0; n <= N; n++) {
			LL t = 1;
			for (int x = 0; x <= n / k; x++) {
				if (x > 0) (t *= comb[n - k*(x - 1)][k]) %= MOD;
				if (x == 0 || (C <= x && x <= D)) {
					LL add = (dp[k - 1][n - k*x] * t) % MOD;
					(add *= inv[x]) %= MOD;
					(dp[k][n] += add) %= MOD;
				}
			}
		}
	}
	cout << dp[B][N] << endl;
}