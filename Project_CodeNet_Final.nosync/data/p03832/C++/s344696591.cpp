#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
ll fact[1001];
ll inv_fact[1001];
ll comb(ll n, ll k) {
	if (n < k) return 0;
	ll ret = fact[n];
	(ret *= inv_fact[k]) %= MOD;
	(ret *= inv_fact[n - k]) %= MOD;
	return ret;
}
ll mod_pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		ll x = mod_pow(a, b / 2);
		return (x*x) % MOD;
	}
	return (a*mod_pow(a, b - 1)) % MOD;
}
ll dp[1001][1001]; //i人の人をj人以下のグループにわける方法が何通りか
int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv_fact[i] = (inv_fact[i - 1] * mod_pow(i, MOD - 2)) % MOD;
	}
	for (int i = 0; i <= N; i++) dp[0][i] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = A; j <= B; j++) {
			(dp[i][j] += dp[i][j - 1]) %= MOD;
			if (j*C > i) continue;
			ll mul = 1;
			int rest = i;
			for (int k = 1; k < C; k++) {
				(mul *= comb(rest, rest - j)) %= MOD;
				rest -= j;
			}
			for (int k = C; k <= min(i/j,D);k++) {
				(mul *= comb(rest, rest - j)) %= MOD;
				rest -= j;
				ll t = (mul*inv_fact[k]) % MOD;
				(dp[i][j] += (dp[i - j * k][j - 1] * t) % MOD) %= MOD;
			}
		}
	}
	cout << dp[N][B] << endl;
}
