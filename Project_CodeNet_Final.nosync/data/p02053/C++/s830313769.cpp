//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()
#define double long double

using namespace std;

int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 200020;

int H, W;
char maze[1010][1010];
vector<P>v, v2;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> H >> W;
	int mnX = INF, mxX = 0, mnY = INF, mxY = 0, mnXY = INF, mxXY = 0, mnXY2 = INF, mxXY2 = 0;
	REP(i, H) {
		REP(j, W) {
			cin >> maze[i][j];
			if (maze[i][j] == 'B') {
				mnX = min(mnX, i);
				mxX = max(mxX, i);
				mnY = min(mnY, j);
				mxY = max(mxY, j);
				mnXY = min(mnXY, i + j);
				mxXY = max(mxXY, i + j);
				mnXY2 = min(mnXY2, (i - j));
				mxXY2 = max(mxXY2, i - j);
				v.push_back({ i,j });
			}
		}
	}
	int N = v.size();
	int ans = 0;
	int s = 0;
	int mx = 0;
	int t = 0;
	//print("here");
	REP(i, N) {
		int x = v[i].first, y = v[i].second;
		if (x == mxX || x == mnX || y == mnY || y == mxY||x+y==mnXY||x+y==mxXY||x-y==mnXY2||x-y==mxXY2) {
			v2.push_back({ x,y });
		}
	}
	
	int M = v2.size();
	REP(i, M - 1) {
		FOR(j, i + 1, M) {
			int res = abs(v2[i].first - v2[j].first) + abs(v2[i].second - v2[j].second);
			ans = max(ans, res);
		}
	}
	/*FOR(j, 1, N) {
		int res = abs(v[s].first - v[j].first) + abs(v[s].second - v[j].second);
		if (res > mx) {
			t = j;
			mx = res;
		}
	}
	REP(i, N) {
		if (i == t)continue;
		int res = abs(v[t].first - v[i].first) + abs(v[t].second - v[i].second);
		ans = max(res, ans);
	}*/
	print(ans);
}

