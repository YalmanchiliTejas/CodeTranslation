#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
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



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	ll d;
	cin >> s >> d;
	int n = s.size();
	vector<vvl> dp(n + 1, vvl(d, vl(2, 0)));
	dp[0][0][1] = 1;
	REP(i, n) {
		REP(j, d) {
			dp[i + 1][(j + s[i] - '0') % d][1] += dp[i][j][1];
			dp[i + 1][(j + s[i] - '0') % d][1] %= MOD;
			REP(k, 10) {
				dp[i + 1][(j + k) % d][0] += dp[i][j][0];
				dp[i + 1][(j + k) % d][0] %= MOD;
			}
			REP(k, s[i] - '0') {
				dp[i + 1][(j + k) % d][0] += dp[i][j][1];
				dp[i + 1][(j + k) % d][0] %= MOD;
			}
		}
	}
	cout << (dp[n][0][1] + dp[n][0][0] + MOD - 1) % MOD << endl;
}