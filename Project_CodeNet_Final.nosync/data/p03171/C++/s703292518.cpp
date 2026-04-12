#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr[3005];
ll dp[3005][3005];
ll rec(ll s,ll e)
{
	if(s==e)
	return arr[s];
	if(dp[s][e]!=-1)
	return dp[s][e];

	dp[s][e]=max(arr[s]-rec(s+1,e),arr[e]-rec(s,e-1));
	return dp[s][e];
}
ll solve(ll n)
{
	
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	
	memset(dp,-1,sizeof(dp));
	
	return rec(0,n-1);//-arr[n-1];
}
int main()
{
	ll t=1,n;
	while(t--)
	{
	
		cin>>n;
		cout<<solve(n)<<endl;
	}


    return 0;
}