#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[3005];
ll dp[3002][3002][2];
ll func(ll i,ll j,int b)
{
	ll d;
	//cout<<i<<" "<<j<<" "<<sum_x<<" "<<sum_y<<endl;
	if(i<1||j<1||i>j)
		return 0;
	if(dp[i][j][b]!=-1)
		return dp[i][j][b];
	if(b)
		dp[i][j][b]=max(func(i,j-1,0)+a[j],func(i+1,j,0)+a[i]);
	else
		dp[i][j][b]=min(func(i,j-1,1)-a[j],func(i+1,j,1)-a[i]);
	return dp[i][j][b];
}
int main()
{
	ll i,n,j;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			dp[i][j][0]=dp[i][j][1]=-1;
	}
	cout<<func(1,n,1)<<endl;
}
