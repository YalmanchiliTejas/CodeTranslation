#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1020, mod = 1e9 + 7, i2 = (mod+1)/2;
ll n, a, b, c, d, dp[maxn][maxn], C[maxn][maxn];
ll bp(ll a, ll p) {
	ll r = 1;
	while(p) {
		if(p&1) r = r*a%mod;
		a = a*a%mod, p>>=1;
	}
	return r;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> a >> b >> c >> d;
	dp[0][a] = 1;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= i; j++) {
			if(!j) C[i][j] = 1;
			else C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
		}
	for(int i = 0; i <= n; i++) {
		for(int j = a; j <= b; j++) {
			//cout << i << " " << j << " " << dp[i][j] << '\n';;
			(dp[i][j+1] += dp[i][j])%=mod;
			ll t = 1;
			for(int k = 0; k < c && n-i-k*j >= 0; k++) {
				t = t*C[n-i-k*j][j]%mod;
				t = t*bp(k+1, mod-2)%mod;
			}
			for(int k = j*c; i+k <= n && k <= j*d; k+=j) {
				(dp[i+k][j+1] += dp[i][j]*t)%=mod;
				t = t*C[n-i-k][j]%mod;
				t = t*bp((k/j)+1, mod-2)%mod;
			}
		}
	}
	cout << dp[n][b+1];
	return 0;
}
