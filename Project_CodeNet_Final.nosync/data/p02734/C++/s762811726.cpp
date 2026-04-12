#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n, s, a[3004]; 
long long ans=0, dp[3004][3004][3];

int main(){
	cin >> n >> s;
	for (int i=0;i<n;i++) cin >> a[i];
	memset(dp,0,sizeof dp);
	dp[0][0][0]=1;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=s;j++){
			// inserting left
			dp[i][j][1]+=dp[i][j][0];
			dp[i][j][1]%=mod;
			// inserting right
			dp[i][j][2]+=dp[i][j][1];
			dp[i][j][2]%=mod;
			// continuing 0
			dp[i+1][j][0]+=dp[i][j][0];
			dp[i+1][j][0]%=mod;
			// include a[i]
			if (a[i]+j<=s){
				dp[i+1][a[i]+j][1]+=dp[i][j][1];
				dp[i+1][a[i]+j][1]%=mod;
			}
			// exclude a[i]
			dp[i+1][j][1]+=dp[i][j][1];
			dp[i+1][j][1]%=mod;
			// continuing 2
			dp[i+1][j][2]+=dp[i][j][2];
			dp[i+1][j][2]%=mod;
		}
	}
	cout << dp[n][s][2] << "\n";	
}