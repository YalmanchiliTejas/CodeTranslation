#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int N,S;
	cin>>N>>S;
	
	vector<int> A(N);
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	
	vector<vector<int>> dp(N+1,vector<int>(S+1,0));
	dp[0][0] = 1;
	
	int ans = 0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<=S;j++){
			dp[i+1][j] = mod(dp[i+1][j] + dp[i][j]);
			int x = j+A[i];
			if(x>S)continue;
			dp[i+1][x] = mod(dp[i+1][x] + dp[i][j]);
		}
		ans = mod(ans + dp[i+1][S]);
		
		dp[i+1][0] = mod(dp[i+1][0] + 1);
	}
	
	cout<<ans<<endl;
	
    return 0;
}
