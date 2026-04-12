/**
 *   
 *   Date: 31 March 2020
 *   Time: 18:23:26
**/
#pragma GCC optimize("03")
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vec;
typedef vector<vector<ll> > matrix;
ll const mod=1000000007;
ll dp[3001][3001][2],ar[3001],n;
ll solve(ll i,ll j,ll x)
{
	if(i>n || j<0 || i>j)
	{

		return 0;
	}
	if(dp[i][j][x] != -1)
		return dp[i][j][x];
	ll ans=0;
	if(x == 0)
	{
		ans=-1e15;
		ans=max(ar[i]+solve(i+1,j,x^1),ar[j]+solve(i,j-1,x^1));
	}
	else
	{
		ans=1e15;
		ans=min(solve(i+1,j,x^1),solve(i,j-1,x^1));
	}
	//return ans;
	return dp[i][j][x]=ans;
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll sum=0,x,y;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>ar[i];
		sum+=ar[i];
	}
	memset(dp,-1,sizeof(dp));
	x=solve(1,n,0);
	y=sum-x;
	cout<<x-y<<endl;

	

return 0;
}