#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

signed main() {
	ll N, S;
	cin >> N >> S;
	vector<ll> A(N);
	for(auto &a : A) cin >> a;

	vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(S+1, vector<ll>(3, 0)));
	dp[0][0][0] = 1;
	for(ll i=1;i<=N;i++) {
		for(ll j=0;j<=S;j++) {
			// i番目まで見た, 左端は決めていない
			dp[i][j][0] += dp[i-1][j][0];
			// i番目まで見た, 左端が決まっている
			dp[i][j][1] += dp[i-1][j][1];
			if(j >= A[i-1]) dp[i][j][1] += dp[i-1][j-A[i-1]][1];
			if(j >= A[i-1]) dp[i][j][1] += dp[i-1][j-A[i-1]][0] * i;

			dp[i][j][2] += dp[i-1][j][2];
			if(j >= A[i-1]) dp[i][j][2] += dp[i-1][j-A[i-1]][1] * (N - i + 1);
			if(j >= A[i-1]) dp[i][j][2] += dp[i-1][j-A[i-1]][0] * i * (N - i + 1);
			for(ll k=0;k<3;k++) dp[i][j][k] %= MOD;
		}
	}
	cout << dp[N][S][2] << endl;
}