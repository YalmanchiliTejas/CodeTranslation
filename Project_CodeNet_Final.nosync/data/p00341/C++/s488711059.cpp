#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

signed main() {
	vector<int> v(12); rep(i, 0, 12) { cin >> v[i]; }
	sort(v.begin(), v.end());
	if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3] &&
		v[4] == v[5] && v[5] == v[6] && v[6] == v[7] &&
		v[8] == v[9] && v[9] == v[10] && v[10] == v[11])cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}