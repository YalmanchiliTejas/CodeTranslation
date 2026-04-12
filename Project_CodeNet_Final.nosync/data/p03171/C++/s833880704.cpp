#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[3001][3001][2];
ll a[3001];
ll solve(ll* a,ll i,ll j,bool turn)
{
	if(i>j)
		return 0;
	if(dp[i][j][turn]!=-1)
	{
		return dp[i][j][turn];
	}
	if(turn==1)
	{
		return dp[i][j][turn]=max(a[i]+solve(a,i+1,j,0),a[j]+solve(a,i,j-1,0));
	}
	else
		return dp[i][j][turn]=min(solve(a,i+1,j,1),solve(a,i,j-1,1));
}
int main()
{
	ll n;
	cin>>n;
	ll sum=0;
	for(ll p=1;p<=n;p++)
	{
		cin>>a[p];
		sum+=a[p];
	}
	memset(dp,-1,sizeof(dp));
	ll ScoreX = solve(a,1,n,1);
	ll ScoreY = sum- ScoreX;
	solve(a,1,n,1);
	cout<<ScoreX-ScoreY<<endl;
}