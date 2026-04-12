#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){

	string N;
	cin>>N;
	int K;
	cin>>K;
	vector<vector<vector<long long>>> dp(N.size()+1,vector<vector<long long>> (K+1,vector<long long>(2,0)));
	
	dp[0][0][0] = 1;
	
	for(int i=0;i<N.size();i++){
		for(int j=0;j<=K;j++){
			if(N[i] == '0'){
				dp[i+1][j][1] += dp[i][j][1];
				dp[i+1][j][0] += dp[i][j][0];
			}
			else{
				dp[i+1][j][1] += dp[i][j][0]+dp[i][j][1];
			}
			
			if(j!=K){
				dp[i+1][j+1][1] += dp[i][j][1] * 9;
				int x = N[i]-'0'-1;
				if(x>=0)dp[i+1][j+1][1] += dp[i][j][0] * x;
				if(N[i]>='1'){
					dp[i+1][j+1][0] += dp[i][j][0];
				}
			}
		}
	}
	
	cout<<dp.back().back()[0] + dp.back().back()[1]<<endl;
	
	return 0;
}