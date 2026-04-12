#include <bits/stdc++.h>
 
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
 
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> P;
 
const ll INF = 1ll<<30;
const ll MOD = 1000000007;
const double EPS  = 1e-10;
 
int n, a, b, c, d;
ll dp[1001][1001];
 
vector<ll> fact, inv;
 
ll mod_pow(ll x, ll n, ll mod) {
	if (n == 0) return 1;
	ll res = mod_pow(x * x % mod, n / 2, mod);
	if (n & 1) res = res * x % mod;
	return res;
}
 
void fact_inv(int n, ll mod) {
	fact.resize(n + 1);
	inv.resize(n + 1);
	
	fact[0] = 1;
	FOR(i, 1, n + 1) fact[i] = fact[i - 1] * i % mod;
	inv[n] = mod_pow(fact[n], mod - 2, mod);
	for (int i = n; i > 0; i--) inv[i - 1] = inv[i] * i % mod;
}
 
ll nCr(ll n, ll r) {
	if (n < r || r < 0 || n < 0) return 0;
	return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}
 
ll dfs(int rem, int mi) {
	if (rem == 0) return 1;
	if (mi > b || rem < mi) return 0;
	
	if (~dp[rem][mi]) return dp[rem][mi];
	
	ll res = dfs(rem, mi + 1);
	
	ll p = 1;
	FOR(i, 1, c) p = p * nCr(rem - mi * (i - 1), mi) % MOD;
	
	FOR(i, c, d + 1) {
		if (rem < mi * i) break;
		p = p * nCr(rem - mi * (i - 1), mi) % MOD;
		
		res += p * dfs(rem - mi * i, mi + 1) % MOD * inv[i] % MOD;
	}
		
	return dp[rem][mi] = res % MOD;
}
 
int main() {
	cin >> n >> a >> b >> c >> d;
	fact_inv(n, MOD);
	
	fill(dp[0], dp[n + 1], -1);
	cout << dfs(n, a) << endl;
	
	return 0;
}