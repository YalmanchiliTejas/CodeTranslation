#include<iostream>
#include<algorithm>
using namespace std;
int H,W;
int A[200];
int dp[200][200];
main()
{
	cin>>H>>W;
	for(int i=0;i<W;i++)for(int j=0;j<W;j++)dp[i][j]=-1e9;
	dp[0][1]=0;
	for(int _=0;_<H;_++)
	{
		for(int i=0;i<W;i++)cin>>A[i];
		for(int i=0;i<W;i++)for(int j=i+1;j<W;j++)
		{
			dp[i][j]+=A[i];
			if(i+1<j)dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
		}
		for(int i=0;i<W;i++)for(int j=i+1;j<W;j++)
		{
			dp[i][j]+=A[j];
			if(j+1<W)dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i+1<W;i++)ans=max(ans,dp[i][W-1]);
	cout<<ans<<endl;
}
