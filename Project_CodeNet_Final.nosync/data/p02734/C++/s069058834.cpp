#include <iostream>
using namespace std;
long long mod=998244353;
long long dp[3001][3001][3];
int main(){
	long long n,s;
	long long a[3000];
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=s;j++){
			(dp[i+1][j][0]+=dp[i][j][0])%=mod;
			(dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1])%=mod;
			(dp[i+1][j][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2])%=mod;
			if(j+a[i]<=s){
				(dp[i+1][j+a[i]][1]+=dp[i][j][0]+dp[i][j][1])%=mod;
				(dp[i+1][j+a[i]][2]+=dp[i][j][0]+dp[i][j][1])%=mod;
			}
		}
	}
	cout<<dp[n][s][2]<<endl;
	return 0;
}