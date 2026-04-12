#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[3000];
ll dp[3000][3000];
ll func(ll low,ll high)
{
	if(low>high)
		return 0;
	if(low==high)
		return arr[low];
	if(dp[low][high]!=-1)
		return dp[low][high];
	ll pos1=arr[low] + min(func(low+2,high),func(low+1,high-1));
	ll pos2=arr[high] + min(func(low,high-2),func(low+1,high-1));
	return dp[low][high] = max(pos1,pos2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,sum=0;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	memset(dp,-1,sizeof dp);
	cout<<2*func(0,n-1)-sum;
}