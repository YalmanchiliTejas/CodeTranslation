#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[3005];
int n;
int dp[3005][3005][2];

int func(int i,int j,int c)
{
	if(dp[i][j][c]!=-1)
		return dp[i][j][c];
	if(i>j)
	{
		return 0;
	}
	if(c==0)
	{
		dp[i][j][c]=max(arr[i]+func(i+1,j,1),arr[j]+func(i,j-1,1));
	}
	else
	{
		dp[i][j][c]=min(-arr[i]+func(i+1,j,0),-arr[j]+func(i,j-1,0));
	}
return dp[i][j][c];
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j][0]=dp[i][j][1]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<func(0,n-1,0);
return 0;
}