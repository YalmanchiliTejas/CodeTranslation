#include<bits/stdc++.h>
using namespace std;

long long int dp[200010][5],i,j,n,a[200010],ans;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (i=1;i<n+1;i++) cin>>a[i];
	if (n==2)
	{
		cout<<max(a[1],a[2]);return 0;
	}
	if (n==3)
	{
		cout<<max(max(a[1],a[2]),a[3]);return 0;
	}
	if (n%2==0)
	{
		ans=0;
		for (i=1;i<n/2+1;i++) ans=ans+a[2*i];
		dp[1][1]=a[1];dp[1][0]=-1e16;
		dp[2][1]=-1e16;dp[2][0]=-1e16;
		for (i=3;i<n+1;i++) for (j=0;j<2;j++)
		{
			dp[i][j]=dp[i-2][j];
			if (j<1 && i>3) if (dp[i-3][j+1]!=-1e16) dp[i][j]=max(dp[i][j],dp[i-3][j+1]);
			if (dp[i][j]!=-1) dp[i][j]=dp[i][j]+a[i];
		}
		
		if (dp[n][0]!=-1e16) ans=max(ans,dp[n][0]);
		if (n>3)
		{
			if (dp[n-1][1]!=-1e16) ans=max(ans,dp[n-1][1]);
		}
		cout<<ans;
		return 0;
	}
	for (i=3;i<n+1;i=i+2) ans=ans+a[i];
	
	
	dp[2][1]=a[2];dp[2][0]=-1e16;
	dp[3][1]=-1e16;dp[3][0]=-1e16;
	for (i=4;i<n+1;i++) for (j=0;j<2;j++)
	{
		dp[i][j]=dp[i-2][j];
		if (j<1) if (dp[i-3][j+1]!=-1e16) dp[i][j]=max(dp[i][j],dp[i-3][j+1]);
		if (dp[i][j]!=-1e16) dp[i][j]=dp[i][j]+a[i];
	}
	
	if (dp[n][0]!=-1e16) ans=max(ans,dp[n][0]);
	if (n>3)
	{
		if (dp[n-1][1]!=-1e16) ans=max(ans,dp[n-1][1]);
	}


	dp[1][2]=a[1];dp[1][1]=-1e16;dp[1][0]=-1e16;
	dp[2][2]=-1e16;dp[2][1]=-1e16;dp[2][0]=-1e16;
	for (i=3;i<n+1;i++) for (j=0;j<3;j++)
	{
		dp[i][j]=dp[i-2][j];
		if (j<2 && i-3>0) if (dp[i-3][j+1]!=-1e16) dp[i][j]=max(dp[i][j],dp[i-3][j+1]);
		if (j<1 && i-4>0) if (dp[i-4][j+2]!=-1e16) dp[i][j]=max(dp[i][j],dp[i-4][j+2]);
		if (dp[i][j]!=-1e16) dp[i][j]=dp[i][j]+a[i];
	}
	
	
	if (dp[n][0]!=-1e16) ans=max(ans,dp[n][0]);
	if (n>3)
	{
		if (dp[n-1][1]!=-1e16) ans=max(ans,dp[n-1][1]);
	}
	if (n>4)
	{
		if (dp[n-2][2]!=-1e16) ans=max(ans,dp[n-2][2]);
	}
	cout<<ans;
}
