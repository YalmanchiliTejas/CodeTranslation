#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string n;
	int k;
	cin >> n >> k;
	vector<vector<vector<int>>> dp(n.size()+1, vector<vector<int>>(k, vector<int>(2, 0)));
	for(int i=0; i<(int)n.size(); ++i){
		if(i == 0){
			dp[i][k-1][0] += n[0]-'0'-1;
			dp[i][k-1][1] += 1;
		}else{
			dp[i][k-1][0] += 9;
		}
		if(i == (int)n.size() - 1) continue;
		if(n[i+1] == '0'){
			dp[i+1][0][1] += dp[i][0][1];
			dp[i+1][0][0] += dp[i][0][0];
		}else{
			dp[i+1][0][0] += dp[i][0][0] + dp[i][0][1];
		}
		for(int j=1; j<k; ++j){
			if(n[i+1] == '0'){
				dp[i+1][j][1] += dp[i][j][1];
				dp[i+1][j][0] += dp[i][j][0];
			}else{
				dp[i+1][j][0] += dp[i][j][0] + dp[i][j][1];
			}
			if(n[i+1] != '0'){
				dp[i+1][j-1][1] += dp[i][j][1];
				dp[i+1][j-1][0] += dp[i][j][1] * (n[i+1]-'0'-1);
			}
			dp[i+1][j-1][0] += dp[i][j][0] * 9;
		}
	}
	int ans = dp[n.size()-1][0][0] + dp[n.size()-1][0][1];
	cout << ans << "\n";
//	for(int i=0; i<(int)n.size(); ++i)
//		for(int j=0; j<k; ++j)
//			cout << i << " " << j << " : " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
}