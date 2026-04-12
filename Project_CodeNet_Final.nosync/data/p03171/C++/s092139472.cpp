#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <math.h>
#include <complex>
#include <cassert>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define case(i) cout<<"Case #"<<i<<": "
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;
typedef complex<double> com;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const ll INF = 1e18;

ll n; vector<vector<ll>> dp; vector<ll> a;
ll ans(int x, int y) {
	if (dp[x][y] != -INF) return dp[x][y];
	if (x == y) return dp[x][y] = a[x];
	else return dp[x][y] = max(a[x] - ans(x + 1, y), a[y] - ans(x, y - 1));
}

int main() { 
	cin >> n; a.resize(n);
	rep(i, 0, n) cin >> a[i];
	dp.resize(n);
	rep(i, 0, n) dp[i].resize(n,-INF);
	cout << ans(0, n - 1) << endl;
	return 0;
}