#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int k;
	cin >> k;

	int n = s.size();

	ll dp[n+1][k+1][2];
	rep(i, n+1) rep(j, k+1) rep(l, 2) dp[i][j][l] = 0;
	dp[0][0][1] = 1;

	rep(i, n) rep(j, k+1){
		// 1 -> 1
		if(s[i] == '0'){
			if(j <= k) dp[i+1][j][1] += dp[i][j][1];
		}else{
			if(j+1 <= k) dp[i+1][j+1][1] += dp[i][j][1]; 
		}

		// 1 -> 0
		if(s[i] != '0'){
			ll t = s[i] - '0';
			if(j+1 <= k) dp[i+1][j+1][0] += (t - 1) * dp[i][j][1];
			if(j <= k) dp[i+1][j][0] += dp[i][j][1];
		}

		// 0 -> 0
		if(j+1 <= k) dp[i+1][j+1][0] += 9LL * dp[i][j][0];
		if(j <= k) dp[i+1][j][0] += dp[i][j][0];
	}

	cout << dp[n][k][0] + dp[n][k][1] << endl;
}
