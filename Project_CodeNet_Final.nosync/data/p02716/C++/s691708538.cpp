#include<bits/stdc++.h>
using namespace std;
long long n,aa[202020],dp[202020][3],sum,sum1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
		sum+=aa[i];
	}
	if(n==3)
	{
		cout<<max(aa[1],max(aa[2],aa[3]))<<endl;
		return 0;
	}
	if(n%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=-1e16;
			dp[i][1]=-1e16;
		}
		dp[1][0]=aa[1];
		dp[2][1]=aa[2];
		for(int i=3;i<=n;i++)
		{
			dp[i][0]=dp[i-2][0]+aa[i];
			dp[i][1]=max(dp[i-3][0],dp[i-2][1])+aa[i];
		}
		cout<<max(dp[n-1][0],dp[n][1])<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][0]=-1e16;
			dp[i][1]=-1e16;
			dp[i][2]=-1e16;
		}
		dp[1][0]=aa[1];
		dp[2][1]=aa[2];
		dp[3][0]=dp[1][0]+aa[3];
		dp[3][2]=dp[0][0]+aa[3];
		for(int i=4;i<=n;i++)
		{
			dp[i][0]=dp[i-2][0]+aa[i];
			dp[i][1]=max(dp[i-3][0],dp[i-2][1])+aa[i];
			dp[i][2]=max(max(dp[i-4][0],dp[i-3][1]),dp[i-2][2])+aa[i];
		}
		cout<<max(dp[n-2][0],max(dp[n-1][1],dp[n][2]))<<endl;
	}
	return 0;
}