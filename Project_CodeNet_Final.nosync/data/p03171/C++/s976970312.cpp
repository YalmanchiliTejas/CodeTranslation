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

ll n;
vector<ll> a(3030);
vector<vector<ll>> dp(3030, vector<ll>(3030, -1));

ll dfs(ll l, ll r) {
	if(dp[l][r] != -1) return dp[l][r];
	ll ret = 0;
	if(l == r) {
		if((n - (r - l + 1)) % 2) ret = -a[l];
		else ret = a[l];
	}
	else {
		if((n - (r - l + 1)) % 2) {
			ret = min(dfs(l + 1, r) - a[l], dfs(l, r - 1) - a[r]);
		} else {
			ret = max(dfs(l + 1, r) + a[l], dfs(l, r - 1) + a[r]);
		}
	}
	return dp[l][r] = ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	REP(i, n) cin >> a[i];
	cout << dfs(0, n - 1) << endl;
	return 0;
}

/* --------------------------------------- */
