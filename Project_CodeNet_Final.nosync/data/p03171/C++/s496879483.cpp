#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18+7)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mkt make_tuple
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x > 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2) % mod;
}
/*--------Library Zone!--------*/

int n, a[3005];
int dp[3005][3005][2];
int solve(int le, int ri, bool x) {
	if (ri - le == 0)return 0;
	if (dp[le][ri][x] != inf)return dp[le][ri][x];
	int res;
	if (!x) {
		res = -inf;
		res = max(res, a[le] + solve(le + 1, ri, 1));
		res = max(res, a[ri - 1] + solve(le, ri - 1, 1));
	}
	else {
		res = inf;
		res = min(res, solve(le + 1, ri, 0) - a[le]);
		res = min(res, solve(le, ri - 1, 0) - a[ri - 1]);
	}
	dp[le][ri][x] = res;
	return res;
}
signed main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n + 1)rep(j, n + 1)rep(k, 2)dp[i][j][k] = inf;
	cout << solve(0, n, 0) << endl;
}