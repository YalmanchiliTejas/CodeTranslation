#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll MOD = 998244353;

	ll n, s;
	cin >> n >> s;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	vector<vector<ll>> dp(n+1, vector<ll>(s+1, 0));

	ll ans = 0;
	rep(i, n){
		rep(j, s+1){
			if(j < s) dp[i+1][j] = dp[i][j];
			if(j - a[i] == 0){
				dp[i+1][j] += i+1;
				dp[i+1][j] %= MOD;
			}else if(j - a[i] > 0){
				dp[i+1][j] += dp[i][j - a[i]];
				dp[i+1][j] %= MOD;
			}
		}

		ans += dp[i+1][s] * (n - i) % MOD;
		ans %= MOD;
	}

	cout << ans << endl;
}
