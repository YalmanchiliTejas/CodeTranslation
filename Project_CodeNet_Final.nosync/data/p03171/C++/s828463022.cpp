#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[3005];
ll dp[3005][3005][3];
ll solve(ll i,ll j,ll turn)
{
	if(i>j)
	return 0;
	else if(i==j&&turn==2)
	return 0;
	else if(i==j&&turn==1)
	return arr[i];
	else if(dp[i][j][turn]!=-1)
	return dp[i][j][turn];
	else
	{
		if(turn==1)
		return dp[i][j][1]=max(arr[i]+solve(i+1,j,2),arr[j]+solve(i,j-1,2));
		else
		return dp[i][j][turn]=min(solve(i+1,j,1),solve(i,j-1,1));
	}
}
int main()
{
		ll n;
		cin>>n;
		ll sum=0;
		for(ll i=0;i<n;i++)
		{
		cin>>arr[i];
		sum+=arr[i];
		}
		memset(dp,-1,sizeof(dp));
		ll x=solve(0,n-1,1);
		cout<<x-(sum-x)<<endl;
		return 0;
	}
		