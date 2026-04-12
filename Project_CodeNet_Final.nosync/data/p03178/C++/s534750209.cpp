#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)


int main(){
	
	string S;
	cin>>S;
	int D;
	cin>>D;
	
	vector<vector<vector<int>>> dp(S.size(),vector<vector<int>> (D,vector<int> (2,0))); //dp[i][j][k] 上からi+1桁、Dで割るとj余る、k=0:制限有 k=1:制限無
	
	int a = S[0] - '0';
	for(int i=0;i<a;i++){
		dp[0][i%D][1] = dp[0][i%D][1]+1;
	}
	dp[0][a%D][0] = 1;
	
	for(int i=1;i<S.size();i++){
		for(int j=0;j<D;j++){
			int b = S[i] - '0';
			dp[i][j][0] = dp[i-1][(j-b+10*D)%D][0];
			for(int k=0;k<b;k++){
				dp[i][j][1] = mod(dp[i-1][(j-k+10*D)%D][0]+dp[i][j][1]);
			}
			for(int k=0;k<10;k++){
				dp[i][j][1] = mod(dp[i][j][1] + dp[i-1][(j-k+10*D)%D][1]);
			}
		}
	}
	
	cout<<mod(dp[S.size()-1][0][0]+dp[S.size()-1][0][1]-1+modulo)<<endl;
	
	return 0;
}
