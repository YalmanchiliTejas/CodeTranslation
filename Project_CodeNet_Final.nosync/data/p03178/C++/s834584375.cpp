#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int main(){
	string k; int D; cin >> k >> D;
	int n = k.size();
	vector<vector<int>> dp(D, vector<int>(2));
	dp[0][0] = 1;
	for(int i = 0; i < n; ++i){
		vector<vector<int>> new_dp(D, vector<int>(2));
		int t = k[i] - '0';
		for(int j = 0; j < D; ++j){
			for(int d = 0; d <= 9; ++d){
				new_dp[(j+d)%D][1] += dp[j][1] + (d<t?dp[j][0]:0);
				new_dp[(j+d)%D][1] %= mod;
			}
			new_dp[(j+t)%D][0] += dp[j][0];
			new_dp[(j+t)%D][0] %= mod;
		}
		dp = new_dp;
	}
	int ans = (dp[0][0] + dp[0][1]) % mod; ans = (ans-1+mod)%mod;
	cout << ans;
}