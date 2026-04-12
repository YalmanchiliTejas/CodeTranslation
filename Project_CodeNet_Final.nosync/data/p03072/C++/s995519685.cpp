#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=1;i<=n;i++)
const long long mod = 1000000007;
const long long inf = 11451419198109130;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<int, PP> PPP;
struct edge { int to; int to2; int cost; };
int h[25];
signed main() {
	int n; cin >> n;
	rep(i, n)cin >> h[i];
	int cnt = 0;
	rep(i, n) {
		int flg = 0;
		rep(j, i ) {
			if (h[j] <= h[i])flg++;
		}
		if (flg == i)cnt++;
	}cout << cnt << endl;
}	
