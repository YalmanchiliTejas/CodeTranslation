#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int,P> PP;
struct edge { int to; int cost; };
int dp[1005][1005];
int kj[1006], kji[1006];
int modpow(int x, int n, int md) {
	if (!n)return 1;
	int res = modpow(x*x%md, n / 2, md);
	if (n & 1)res = res*x%mod;
	return res;
}
int comb(int r, int c) {
	if (r < c || c < 0)return 0;
	return kj[r] * kji[c] % mod*kji[r - c] % mod;
}
signed main() {
	kj[0] = 1;
	for (int i = 1; i <= 1001; i++)kj[i] = kj[i - 1] * i%mod;
	rep(i, 1001)kji[i] = modpow(kj[i], mod - 2, mod);
	int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
	dp[0][0] = 1;
	for (int I = 0; I <= b - a; I++) {
		int i = I + a;
		rep(j, n+1) {
			dp[I + 1][j] += dp[I][j];
			dp[I + 1][j] %= mod;
			for (int k = c; k <= d; k++) {
				int t = i*k + j;
				if (t > n)break;
				dp[I + 1][t] += dp[I][j] * (kj[n-j]*kji[n-t]%mod*modpow(kji[i],k,mod)%mod*kji[k] % mod);
				dp[I + 1][t] %= mod;
			}
		}
	}
	cout << dp[b - a + 1][n] << endl;
/*	rep(i, b - a + 2) {
		rep(j, n + 1) {
			cout << dp[i][j] << ' ';
		}cout << endl;
	}*/
}