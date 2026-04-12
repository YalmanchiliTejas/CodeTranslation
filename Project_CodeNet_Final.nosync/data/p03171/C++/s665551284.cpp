#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[3007];
ll dp[3007][3007][2];
ll f(ll i,ll j,ll k)
{
	if(i>j)
		return 0;
	if(dp[i][j][k]!=-1)
		return dp[i][j][k];
	if(k==0)
		return dp[i][j][k]=max(arr[i]+f(i+1,j,1),arr[j]+f(i,j-1,1));
	else
		return dp[i][j][k]=min(f(i+1,j,0)-arr[i],f(i,j-1,0)-arr[j]);
}
int main()
{
	ll n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	cout<<f(0,n-1,0);
	return 0;
}
