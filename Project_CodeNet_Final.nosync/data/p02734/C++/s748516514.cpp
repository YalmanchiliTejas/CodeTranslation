#include "bits/stdc++.h"
using namespace std;

const int N=3e3+20,MOD=998244353;

int n,s,x,dp[N][N],ans;

int main()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		memcpy(dp[i],dp[i-1],sizeof(dp[0]));
		dp[i][x]=(dp[i][x]+i)%MOD;
		for(int j=0;j+x<=s;j++)
			dp[i][j+x]=(dp[i][j+x]+dp[i-1][j])%MOD;
		ans=(dp[i][s]+ans)%MOD;
	}
	cout<<ans;
}