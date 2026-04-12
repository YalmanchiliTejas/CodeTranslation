#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

string k;
ll d;
ll n;
ll dp[10010][100][2];

ll dfs(ll a, ll b, ll c) {
	if(dp[a][b][c] != -1) return dp[a][b][c];
	ll ret = 0;
	if(!a) {
		REP(i, 10) {
			if(!c && i > (k[a] - '0')) break;
			if(i % d == b) ret++;
		}
	} else {
		REP(i, 10) {
			if(!c && i > (k[a] - '0')) break;
			ll rem = ((b - i) % d + d) % d;
			if(!c && i != (k[a] - '0')) {
				ret += dfs(a - 1, rem, !c);
			} else {
				ret += dfs(a - 1, rem, c);
			}
		}
	}
	return dp[a][b][c] = ret % MOD;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> k >> d;
	n = (ll)k.size();
	reverse(ALL(k));
	REP(i, 10010) REP(j, 100) REP(k, 2) dp[i][j][k] = -1;
	cout << ((dfs(n - 1, 0, 0) - 1) % MOD + MOD) % MOD << endl;
	return 0;
}

/* --------------------------------------- */
