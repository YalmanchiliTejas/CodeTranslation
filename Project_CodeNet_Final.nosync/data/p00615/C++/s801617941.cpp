#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DEBUG 0
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define dump(o) if(DEBUG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DEBUG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
using ll = long long; using ull = unsigned long long; using pii = pair<int, int>;
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
static const int MOD = 1e9 + 7;

signed main() {
	int a[20010] = {};
	for (int n, m; cin >> n >> m && (n || m);) {
		rep(i, 0, n + m)cin >> a[i];
		a[n + m] = 0;
		sort(a, a + n + m + 1);
		int M = 0;
		rep(i, 1, n + m + 1) {
			M = max(M, a[i] - a[i - 1]);
		}
		cout << M << endl;
	}
	return 0;
}