#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


const int MX = 3100;

int n;
ll MOD;
ll cnk[MX][MX];
ll dp[MX][MX];

ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> MOD;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j) {
			if (i == j || j == 0)
				cnk[i][j] = 1;
			else if (j > i)
				cnk[i][j] = 0;
			else
				cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % MOD;
		}
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (j + 1)) % MOD;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
		}
	}
	ll ans = 0;
	for (int k = 0; k <= n; ++k) {
		ll now = 0;
		ll cur = 1;
		--MOD;
		ll av = pw(2, n - k);
		++MOD;
		ll p = pw(2, av) * cnk[n][k] % MOD;
		av = pw(2, n - k);
		for (int j = 0; j <= k; ++j) {
			now = (now + cur * dp[k][j]) % MOD;
			cur = (cur * av) % MOD;
		}
		now = (now * p) % MOD;
		if (k % 2 == 0)
			ans = (ans + now) % MOD;
		else
			ans = (ans - now + MOD) % MOD;
	}
	cout << ans << "\n";
	return 0;
}


