#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1ll<<30;
const ll longINF = 1ll<<60;
const ll MOD = 1000000007;
const bool debug = 0;
//---------------------------------//

ll mod_pow(ll x, ll n, ll mod = MOD) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) res = res * x % mod;
	
	return res;
}

vector<ll> fact, inv;
void fact_inv(int n, ll mod = MOD) {
	fact.resize(n + 1);
	inv.resize(n + 1);
	
	fact[0] = 1;
	FOR(i, 1, n + 1) fact[i] = fact[i - 1] * i % mod;
	inv[n] = mod_pow(fact[n], mod - 2, mod);
	for (int i = n; i > 0; i--) inv[i - 1] = inv[i] * i % mod;
}

ll ncr(ll n, ll r, ll mod = MOD) {
	if (n < r || n < 0 || r < 0) return 0;
	if (r > n - r) r = n - r;
	ll res = 1;
	for (ll i = n; i >= n - r + 1; i--) res = res * i % mod;
	res = res * inv[r] % mod;
	return res;
}

ll solve(ll H, ll W, ll K) {
	ll res = 0;
	
	ll allp = ncr(H * W - 2, K - 2);
	
	FOR(w, 1, W + 1) {
		ll pat = W - w;
		pat = pat * H % MOD * H % MOD * allp % MOD;
		res = (res + pat * w % MOD) % MOD;
	}
	
	return res;
}

int main() {
	fact_inv(212345);
	
	int N, M;
	ll K;
	cin >> N >> M >> K;
	
	ll ans = (solve(N, M, K) + solve(M, N, K)) % MOD;
	cout << ans << endl;
	
	return 0;
}
