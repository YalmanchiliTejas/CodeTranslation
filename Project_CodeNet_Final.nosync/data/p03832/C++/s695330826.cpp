#include <bits/stdc++.h>
#define PII pair<int, int>
#define LL long long
using namespace std;
const int MAXN = 1005;
const LL INF = (LL)1e9 + 5;
const LL MOD = 1000000007;

LL dp[MAXN][MAXN], inv[MAXN], c[MAXN][MAXN];

LL mod_inv(LL x) {
	LL pw = MOD - 2, res = 1;
	while (pw) {
		if (pw & 1) res = res * x % MOD;
		x = x * x % MOD;
		pw >>= 1;
	}
	return res;
}

LL solve(LL N, LL A, LL B, LL C, LL D) {
	dp[A - 1][0] = 1;
	fill(dp[A - 1] + 1, dp[A - 1] + MAXN, 0);
	for (int i = A; i <= B; i++) {
		for (int j = 0; j <= N; j++) {
			LL prod = 1;
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= D && k * i <= j; k++) {
				LL rem = j - k * i;
				prod = prod * inv[k] % MOD* c[rem + i][i] % MOD;
				if (k < C) continue;
				dp[i][j] = (dp[i][j] + prod * dp[i - 1][rem]) % MOD;
			}
		}
	}
	return dp[B][N];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	LL N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	
	for (int i = 1; i <= N; i++) {
		inv[i] = mod_inv(i);
	}
	
	for (int n = 0; n <= N; n++) {
		for (int k = 0; k <= n; k++) {
			c[n][k] = (k == 0 || k == n ? 1 : (c[n - 1][k] + c[n - 1][k - 1]) % MOD);
		}
	}
	
	cout << solve(N, A, B, C, D) << '\n';

	return 0;
}