#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[aa]; if (aa != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }
ll mypow(ll a, ll n) {
	if (n == 0)return 1;
	ll d = mypow(a, n / 2);
	if (n & 1)return d * d%MOD*a%MOD;
	return d * d%MOD;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	vvl dp(n + 1, vl(n+1,0));
	vl fact(n + 1), rfact(n + 1);
	fact[0] = 1;
	REP(i, n) {
		fact[i + 1] = (fact[i] * (i + 1)) % MOD;
	}
	REP(i, n + 1) {
		rfact[i] = mypow(fact[i], MOD - 2);
	}
	dp[0][0] = 1;
	REP(i, n) {
		REP(j, n+1) {
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= MOD;
			if (i+1 >= a && i+1 <= b) {
				FOR(k, c, d + 1) {
					if (j + (i+1) * k > n)break;
					dp[i + 1][j + (i+1) * k] += dp[i][j] * mypow(rfact[i + 1], k) % MOD*fact[n - j] % MOD*rfact[n - j - (i+1) * k] % MOD*rfact[k] % MOD;
					dp[i + 1][j + (i+1) * k] %= MOD;
				}
			}

		}
	}
	cout << dp[n][n] << endl;
}
