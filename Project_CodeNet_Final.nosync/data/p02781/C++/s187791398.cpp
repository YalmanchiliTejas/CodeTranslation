#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	int n, k;
	cin >> s >> k;
	n = s.size();
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(2, 0)));
	dp[0][k-1][0] = s[0]-'0'-1;
	dp[0][k-1][1] = 1;
	for(int i=1; i<n; ++i){
		dp[i][k-1][0] = 9;
		for(int j=0; j<k; ++j){
			if(s[i] == '0'){
				dp[i][j][1] += dp[i-1][j][1];
				dp[i][j][0] += dp[i-1][j][0];
			}else{
				dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][1];
			}
		}
		for(int j=1; j<=9; ++j){
			if(j == s[i]-'0'){
				for(int l=0; l<k; ++l){
					dp[i][l][1] += dp[i-1][l+1][1];
					dp[i][l][0] += dp[i-1][l+1][0];
				}
			}else if(j < s[i]-'0'){
				for(int l=0; l<k; ++l)
					dp[i][l][0] += dp[i-1][l+1][0] + dp[i-1][l+1][1];
			}else{
				for(int l=0; l<k; ++l)
					dp[i][l][0] += dp[i-1][l+1][0];
			}
		}
	}
	cout << dp[n-1][0][0] + dp[n-1][0][1] << "\n";
//	for(int i=0; i<n; ++i)
//		for(int j=0; j<k; ++j)
//			cout << i << " " << j << " : " << dp[i][j][0] << " " << dp[i][j][1] << "\n";
}