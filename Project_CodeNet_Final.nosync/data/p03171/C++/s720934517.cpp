#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define nl "\n"
ll n;
ll a[3002];
ll dp[3002][3002][2];
ll f(ll l,ll r,ll turn)
{
	if(l==r)
	{
		if(turn==0)
		{
			dp[l][r][turn] = a[l];
			return a[l];
		}
		else
		{
			dp[l][r][turn] = -a[r];
			return -a[l];
		}
	}
	if(l>r)
		return 0;
	if(l+1==r)
	{
		if(turn == 0)
			dp[l][r][turn] = max(a[l]-a[r],a[r]-a[l]);
		else
			dp[l][r][turn] = min(a[r]-a[l],a[l]-a[r]);
	}
	if(dp[l][r][turn] == -1)
	{
		if(turn == 0)
			dp[l][r][turn] = max(a[l]+f(l+1,r,1),a[r]+f(l,r-1,1));
		else
			dp[l][r][turn] = min(f(l+1,r,0)-a[l],f(l,r-1,0)-a[r]);
	}
	return dp[l][r][turn];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	ll i,j,k;
	ll ans=0;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<3002;i++)
		for(j=0;j<3002;j++)
			for(k=0;k<2;k++)
				dp[i][j][k]=-1;
	f(0,n-1,0);
	cout<<dp[0][n-1][0]<<nl;
	return 0;
}