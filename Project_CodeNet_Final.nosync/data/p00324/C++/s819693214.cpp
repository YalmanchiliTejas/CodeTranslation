#include "bits/stdc++.h"
using namespace std;

#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<(o)<<" ";}
#define dumpl(o) if(DBG){cerr<<#o<<" "<<(o)<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

signed main() {
	int N; cin >> N;
	vector<int> v(N + 1); v[0] = 0; rep(i, 0, N) { cin >> v[i + 1]; }
	rep(i, 1, N + 1) {
		v[i] += v[i - 1];
	}
	unordered_map<int, int> mp;
	int ans = 0;
	rep(i, 0, N + 1) {
		if (mp.count(v[i])) {
			chmax(ans, i - mp[v[i]]);
		}
		else
			mp[v[i]] = i;
	}
	cout << ans << endl;
	return 0;
}