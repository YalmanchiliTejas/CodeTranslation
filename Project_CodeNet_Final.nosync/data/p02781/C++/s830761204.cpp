#include <bits/stdc++.h>
using namespace std;
int main(){
	string N; int K; cin >> N >> K; 
	long long dp[110][4][2] = {}; 
	dp[0][0][0] = 1; 
	for(int i = 1; i <= N.size(); i++){
		if(N.at(i-1) == '0'){
			dp[i][0][0] = dp[i-1][0][0]; 
			dp[i][1][0] = dp[i-1][1][0]; 
			dp[i][2][0] = dp[i-1][2][0]; 
			dp[i][3][0] = dp[i-1][3][0]; 
			dp[i][0][1] = dp[i-1][0][1]; 
			dp[i][1][1] = dp[i-1][0][1] * 9 + dp[i-1][1][1]; 
			dp[i][2][1] = dp[i-1][1][1] * 9 + dp[i-1][2][1];   
			dp[i][3][1] = dp[i-1][2][1] * 9 + dp[i-1][3][1];  
		}
		else{
			dp[i][0][0] = 0; 
			dp[i][1][0] = dp[i-1][0][0]; 
			dp[i][2][0] = dp[i-1][1][0]; 
			dp[i][3][0] = dp[i-1][2][0]; 
			dp[i][0][1] = dp[i-1][0][1] + dp[i-1][0][0]; 
			dp[i][1][1] = dp[i-1][0][1] * 9 + dp[i-1][1][1] + dp[i-1][0][0] * (N.at(i-1) - '1') + dp[i-1][1][0]; 
			dp[i][2][1] = dp[i-1][1][1] * 9 + dp[i-1][2][1] + dp[i-1][1][0] * (N.at(i-1) - '1') + dp[i-1][2][0];    
			dp[i][3][1] = dp[i-1][2][1] * 9 + dp[i-1][3][1] + dp[i-1][2][0] * (N.at(i-1) - '1') + dp[i-1][3][0];    
		}
	}
	cout << dp[N.size()][K][0] + dp[N.size()][K][1] << endl; 
}