#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = ll(1e9 + 7);
ll dp[2020][2020];
ll s[2020][2020];

ll modpow(ll x, ll y, ll m) {
	if(y == 0) return 1;
	ll res = modpow(x, y / 2, m);
	return res * res % m * (y & 1 ? x : 1) % m;
}

ll inv[2020];
ll modinv(ll x, ll m) {
	if(inv[x] != 0) return inv[x];
	return inv[x] = modpow(x, m - 2, m);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif

	for(int i = 1; i < 2020; i++) {
		inv[i] = modinv(i, MOD);
	}

	ll N, D, X;
	while(cin >> N >> D >> X, N) {
		X--;
		if(X == 0) {
			//cout << 0 << endl;
			//continue;
		}

		memset(dp, 0, sizeof dp);
		memset(s, 0, sizeof s);
		dp[0][0] = 1;
		for(int i = 0; i <= N; i++) {
			s[0][i + 1] = s[0][i] + dp[0][i];
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				int l = max(0LL, j - X);
				int r = j;
				dp[i][j] = (s[i - 1][r] - s[i - 1][l] + MOD) % MOD;
				s[i][j + 1] = (s[i][j] + dp[i][j]) % MOD;
			}
		}
		ll ans = 0;
		for(int i = 1; i <= min(N, D); i++) {
			if(dp[i][N] == 0) continue;
			ll comb = 1;
			for(ll j = 0; j < i; j++) {
				comb *= (D - j) % MOD;
				comb %= MOD;
			}
			for(ll j = 1; j <= i; j++) {
				comb *= inv[j];
				comb %= MOD;
			}
			ans += dp[i][N] * comb % MOD;
			ans %= MOD;
		}
		cout << ans << endl;
	}
}