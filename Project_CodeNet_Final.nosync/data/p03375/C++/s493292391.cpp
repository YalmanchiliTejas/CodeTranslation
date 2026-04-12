#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

ll MOD;

ll mod_pow(ll a, ll n, ll MOD) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		ll t = mod_pow(a, n / 2, MOD);
		return t * t%MOD;
	}
	return a * mod_pow(a, n - 1, MOD) % MOD;
}

vector<ll> fact;
vector<ll> inv_fact;
vector<ll> inv;

void comb_init(int n) {
	fact.resize(n + 1);
	inv_fact.resize(n + 1);
	inv.resize(n + 1);
	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i%MOD;
		inv[i] = mod_pow(i, MOD - 2, MOD);
		inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
	}
}

ll comb(int n, int k) {
	if (n < k) return 0;
	ll ret = fact[n];
	(ret *= inv_fact[k]) %= MOD;
	(ret *= inv_fact[n - k]) %= MOD;
	return ret;
}

ll ways[3001];
ll ways2[3001][3001];

int main() {
	int N;
	cin >> N >> MOD;
	ways2[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j > 0) (ways2[i][j] += ways2[i - 1][j - 1]) %= MOD;
			(ways2[i][j] += ways2[i - 1][j] * (j + 1) % MOD) %= MOD;
		}
	}
	for (int i = 0; i <= N; i++) {
		ll sum = 0;
		for (int j = 0; j <= i; j++) {
			(sum += ways2[i][j] * mod_pow(2, j*(N - i), MOD) % MOD) %= MOD;
		}
		(sum *= mod_pow(2, mod_pow(2, N - i, MOD - 1), MOD)) %= MOD;
		ways[i] = sum;
	}
	comb_init(N);
	ll ans = 0;
	for (int i = 0; i <= N; i++) {
		ll x = ways[i] * comb(N, i) % MOD;
		if (i % 2 == 0) (ans += x) %= MOD;
		else (ans += MOD - x) %= MOD;
	}
	cout << ans << endl;
}
