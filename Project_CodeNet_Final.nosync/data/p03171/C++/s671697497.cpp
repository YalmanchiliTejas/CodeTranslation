#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[3002][3002];
ll a[3002];
void solve (ll i, ll j, ll c)
{
	if (dp[i][j]!=-1)
		return;
	else
	{
		if (c)
		{
			c=0;
			if (i==j)
			{
				ll ans=a[i];
				dp[i][j]=-ans;
				return;
			}
			else if (i<j)
			{
				solve(i+1,j,c);
				solve(i,j-1,c);
				dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);	
				return;
			}	
			else
			{
				dp[i][j]=0;
				return;
			}
		}
		else
		{
			c=1;
			if (i==j)
			{
				ll ans=a[i];
				dp[i][j]=ans;
				return;
			}
			else if (i<j)
			{
				solve(i+1,j,c);
				solve(i,j-1,c);
				dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
				return;
			}	
			else
			{
				dp[i][j]=0;
				return;
			}
		}
	}
}
int main()
{
	ll n;
	cin>>n;
	for (ll i=1;i<=n;i++)
		cin>>a[i];
	for (ll i=0;i<=n;i++)
	{
		for (ll j=0;j<=n;j++)
			{
				dp[i][j]=-1;	
			}
	}
	solve(1,n,0);
	cout<<dp[1][n];
}