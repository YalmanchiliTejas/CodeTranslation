#include <bits/stdc++.h>
using namespace std;

const int mod=998244353;
int main()
{
	int n,s;
	cin>>n>>s;
	int a[n+1],dp[n+1][3005];
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(dp,0,sizeof(dp));
	//dp[0][0]=1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s;j++)
		{
			//if(a[i]==j)continue;
			dp[i][j]+=dp[i-1][j];
			dp[i][j]%=mod;
		}
		dp[i][a[i]]+=i;
		dp[i][a[i]]%=mod;
		for(int j=a[i];j<=s;j++)
		{
			dp[i][j]+=dp[i-1][j-a[i]];
			dp[i][j]%=mod;
		}
		
		ans+=dp[i][s];ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}