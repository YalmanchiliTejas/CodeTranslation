#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#define rep(i,n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
typedef pair<int, int> P;
ll mod_pow(ll a, ll n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		ll tmp = mod_pow(a, n / 2);
		return (tmp * tmp) % MOD;
	}
	return (a * mod_pow(a, n - 1)) % MOD;
}

vector<ll> fact;
vector<ll> inv_fact;

void comb_init(int n) {
	fact.resize(n + 1);
	inv_fact.resize(n + 1);
	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		inv_fact[i] = (inv_fact[i - 1] * mod_pow(i, MOD - 2)) % MOD;
	}
}

ll comb(int n, int k) {
	if (n < k) return 0;
	ll ret = fact[n];
	(ret *= inv_fact[k]) %= MOD;
	(ret *= inv_fact[n - k]) %= MOD;
	return ret;
}
int main() {
	ll N, M, K;
	cin >> N >> M >> K;
	ll ans = 0;
	comb_init(N*M);
	for (int i = 1; i < N; i++) {
		ll t = (N - i)*M*M%MOD;
		(t *= comb(N*M - 2, K - 2)) %= MOD;
		(t *= i) %= MOD;
		(ans += t) %= MOD;
	}
	for (int i = 1; i < M; i++) {
		ll t = (M - i)*N*N%MOD;
		(t *= comb(N*M - 2, K - 2)) %= MOD;
		(t *= i) %= MOD;
		(ans += t) %= MOD;
	}
	cout << ans << endl;
}