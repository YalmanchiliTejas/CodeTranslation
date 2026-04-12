#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define all(v) v.begin(),v.end()
#define prique(T) priority_queue<T,vector<T>,greater<T>>
using namespace std;

template<class T> inline void chmax(T &a, T b) {
	a = std::max(a, b);
}
template<class T> inline void chmin(T &a, T b) {
	a = std::min(a, b);
}

int mod_pow(int x, int y, int m = mod) {
	int res = 1;
	while (y) {
		if (y % 2) {
			res *= x;
			res %= m;
		}
		x = x * x % mod;
		y /= 2;
	}
	return res;
}
int kai[1005];
void init() {
	kai[0] = 1;
	REP(i,1001)
		kai[i] = kai[i - 1] * i % mod;
}
int comb(int x, int y) {
	if (y > x)
		return 0;
	return kai[x] * mod_pow(kai[x - y], mod - 2, mod) % mod
			* mod_pow(kai[y], mod - 2, mod) % mod ;
}

int n, a, b, c, d;
int dp[1005][1005];
signed main() {
	init();
	cin >> n >> a >> b >> c >> d;
	dp[0][0] = 1;
	rep(i,n)
	{
		rep(j,n+1)
		{
			dp[i][j] %= mod;
			dp[i][j + 1] += dp[i][j];
		}
		for (int k = 1; k <= n; k++) {
			if (k < a || k > b)
				continue;
			int ans = 1ll;
			for (int l = 1;; l++) {
				int m = i + k * l, pre = i + k * (l - 1);
				if (m > n || l > d)
					break;
				ans *= comb(n - pre, k);
				ans %= mod;
				int memo = ans * mod_pow(kai[l], mod - 2, mod);
				memo %= mod;
				if (l >= c) {
					dp[m][k] += memo * dp[i][k - 1];
					dp[m][k] %= mod;
				}
			}
		}
	}
	int sum = 0;
	rep(i,n+1)
		sum += dp[n][i];
	cout << sum % mod << endl;
}
