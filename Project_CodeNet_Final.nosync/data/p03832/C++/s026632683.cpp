#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = ll(1e9 + 7);
ll N, A, B, C, D;

ll dp[1010][1010];
ll fact[1010];
ll factinv[1010];
ll p[1010][1010];

ll modpow(ll x, ll y, ll m) {
	if(y == 0) return 1;
	ll res = modpow(x, y / 2, m);
	return res * res % m * (y & 1 ? x : 1) % m;
}

ll modinv(ll x, ll m) {
	return modpow(x, m - 2, m);
}

ll f(ll rem, ll g) {
	if(dp[rem][g] != -1) return dp[rem][g];
	if(rem == 0) return 1;
	if(g > B) return 0;
	if(g * C > rem) return 0;

	ll sum = 0;
	int r = rem;
	sum += f(r, g + 1);
	ll c = 1;
	for(int i = 1; i <= C; i++) {
		c = c * p[r][g] % MOD;
		r -= g;
	}
	for(int i = C; i <= D; i++) {
		sum = (sum + f(r, g + 1) * c  % MOD * factinv[i]) % MOD;

		c = c * p[r][g] % MOD;
		r -= g;
		if(r < 0) break;
	}
	return dp[rem][g] = sum;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	fact[0] = fact[1] = 1;
	for(int i = 2; i < 1010; i++) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	for(int i = 0; i < 1010; i++) {
		factinv[i] = modinv(fact[i], MOD);
	}
	for(int i = 0; i <= 1000; i++) {
		for(int j = 0; j <= i; j++) {
			if(j == 0 || j == i)
				p[i][j] = 1;
			else
				p[i][j] = (p[i - 1][j - 1] + p[i - 1][j]) % MOD;
		}
	}

	cin >> N >> A >> B >> C >> D;
	memset(dp, -1, sizeof dp);
	cout << f(N, A) << endl;
}