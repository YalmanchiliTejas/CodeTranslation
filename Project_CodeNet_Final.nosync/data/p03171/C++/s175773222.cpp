#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n,x;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll dp[n][n][2];
	for(int i=0;i<n;i++)
	{
		dp[i][i][1]=a[i];
		dp[i][i][0]=-a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int l=0,r=i;r<n;r++,l++)
		{
			dp[l][r][0]=min(dp[l+1][r][1]-a[l],dp[l][r-1][1]-a[r]);
			dp[l][r][1]=max(dp[l+1][r][0]+a[l],dp[l][r-1][0]+a[r]);
		}
	}
	cout<<dp[0][n-1][1];
	return 0;
}