#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
//#define int long long
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

ll dp[200010][3][2];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n + 1) rep(j, 3) rep(k, 2) dp[i][j][k] = -INF;
	dp[0][0][0] = a[0];
	dp[0][1][1] = 0;
	rep(i, n) {
		rep(j, 3) {
			chmax(dp[i + 1][j][1], dp[i][j][0]);
		}
		rep(j, 2) {
			chmax(dp[i + 1][j + 1][1], dp[i][j][1]);
		}
		rep(j, 3) {
			if (i != n - 1) chmax(dp[i + 1][j][0], dp[i][j][1] + a[i + 1]);
		}
	}
	ll ans = -INF;
	if (!(n & 1)) rep(j, 2) rep(k, 2) chmax(ans, dp[n][j][k]);
	if (n & 1) rep(j, 2) rep(k, 2) chmax(ans, dp[n][j + 1][k]);
	cout << ans << '\n';
} 