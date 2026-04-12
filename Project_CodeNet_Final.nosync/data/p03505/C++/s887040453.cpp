#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

/* --------------------------------------- */

int main() {
//	ios::sync_with_stdio(false);
	cin.tie(0);
	ll _k, _a, _b;
	cin >> _k >> _a >> _b;
	__int128 k = _k, a = _a, b = _b;
	if(a <= b) {
		if(a >= k) cout << "1" << endl;
		else cout << "-1" << endl;
		return 0;
	}
	__int128 lb = -1, ub = INF * INF + INF;
	while(ub - lb > 1) {
		__int128 mid = (lb + ub) / 2;
		if(mid * a - (mid - 1) * b >= k) ub = mid;
		else lb = mid;
	}
	cout << (ll)(ub * 2 - 1) << endl;
	return 0;
}

/* --------------------------------------- */
