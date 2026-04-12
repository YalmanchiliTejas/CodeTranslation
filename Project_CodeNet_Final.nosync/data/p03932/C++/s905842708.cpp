#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
	int H, W; cin >> H >> W;
	vector<vector<int> > a(H, vector<int>(W));
	rep(y, H) rep(x, W) cin >> a[y][x];
	vector<vector<int> > dp(H + 1, vector<int>(H + 1, INT_MIN));
	dp[0][0] = 0;
	rep(z, H + W - 2) {
		vector<vector<int> > _dp(H + 1, vector<int>(H + 1, INT_MIN));
		rep(y1, H) rep(y2, H) {
			int x1 = z - y1, x2 = z - y2;
			if (!(0<=x1 && x1<W && 0<=x2 && x2<W)) continue;
			int unko = dp[y1][y2] + a[y1][x1];
			if (y1 != y2) unko += a[y2][x2];
			_dp[y1][y2] = max(_dp[y1][y2], unko);
			_dp[y1 + 1][y2] = max(_dp[y1 + 1][y2], unko);
			_dp[y1][y2 + 1] = max(_dp[y1][y2 + 1], unko);
			_dp[y1 + 1][y2 + 1] = max(_dp[y1 + 1][y2 + 1], unko);
		}
		dp = _dp;
	}
	cout << dp[H - 1][H - 1] + a[H - 1][W - 1] << endl;
}
