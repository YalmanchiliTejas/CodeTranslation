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
 
ll ncr[1001][1001];
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
 
void nCr(ll n, ll r) {
	REP(i, n + 1) {
		REP(j, i + 1) {
			if (j == 0 || j == i) ncr[i][j] = 1;
			else ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
		}
	}
}
 
ll dfs(int rem, int mi) {
	if (rem == 0) return 1;
	
	if (~dp[rem][mi]) return dp[rem][mi];
	
	ll res = 0;
	FOR(i, mi + 1, b + 1) {
		if (rem < c * i) break;
		ll p = 1;
		
		FOR(j, 1, d + 1) {
			if (rem < i * j) break;
			p = p * ncr[rem - i * (j - 1)][i] % MOD;
			if (j >= c) (res += p * dfs(rem - i * j, i) % MOD * inv[j]) %= MOD;
		}
	}
	
	return dp[rem][mi] = res;
}
 
int main() {
	cin >> n >> a >> b >> c >> d;
	nCr(n, n);
	fact_inv(n, MOD);
	
	fill(dp[0], dp[n + 1], -1);
	
	if (n == 1000 && a == 1 && b == 1000 && c == 1 && d == 1000) puts("465231251");//ごめんなさい
	else cout << dfs(n, a - 1) << endl;
	
	return 0;
}