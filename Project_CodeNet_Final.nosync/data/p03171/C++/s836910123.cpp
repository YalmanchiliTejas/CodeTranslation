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

ll dfs(vector<vvl> &dp, vl &v, int i, int j, int t) {
	if (i > j)return 0;
	if (dp[i][j][t] != -1)return dp[i][j][t];

	if (t == 0) {
		ll ret = -INF * INF;
		ret = max(ret, dfs(dp, v, i + 1, j, 1) + v[i]);
		ret = max(ret, dfs(dp, v, i, j - 1, 1) + v[j]);
		return dp[i][j][t] = ret;
	}
	else {
		ll ret = INF * INF;
		ret = min(ret, dfs(dp, v, i + 1, j, 0) - v[i]);
		ret = min(ret, dfs(dp, v, i, j - 1, 0) - v[j]);
		return dp[i][j][t] = ret;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int  n;
	cin >> n;
	vl v(n);
	REP(i, n)cin >> v[i];
	vector<vvl> dp(n, vvl(n, vl(2, -1)));
	dfs(dp, v, 0, n - 1, 0);
	cout << dp[0][n - 1][0] << endl;
}