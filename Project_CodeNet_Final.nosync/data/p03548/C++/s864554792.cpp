#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define FOR(i,a,b) for(size_t i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

typedef pair<ll, ll> pll;
// const ll INF = (ll)1e18;

signed main() {
	int x, y, z;
	cin >> x >> y >> z;
	int res = ((x - z) / (y + z));
	cout << res << endl;
}
