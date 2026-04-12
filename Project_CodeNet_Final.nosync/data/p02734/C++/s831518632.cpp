#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

signed main(){
	ll N, S;
	cin >> N >> S;
	vector<ll> A(N);
	for(auto &a : A) cin >> a;
	vector<vector<ll>> dp(N+1, vector<ll>(S+1, 0));

	for(int i=0;i<=N;i++) dp[i][0] = 1;

	for(int i=1;i<=N;i++) {
		for(int j=0;j<=S;j++) {
			dp[i][j] += dp[i-1][j];
			if(j >= A[i-1]) dp[i][j] += dp[i-1][j-A[i-1]];
			dp[i][j] %= MOD;
		}
	}
	ll ans = 0;
	for(int i=0;i<=N;i++) {
		ans += dp[i][S];
		ans %= MOD;
	}
	cout << ans << endl;
}