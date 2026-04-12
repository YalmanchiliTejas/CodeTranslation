#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld double
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define pll pair <ll,ll>
#define nl "\n"
ll a[3002],dp[3002][3002][2];
ll n;
ll fx(ll i, ll j, ll turn)
{
	if(i>j)
		return dp[i][j][turn]=0;
	if(i==j)
	{
		if(turn == 0)
			return dp[i][j][turn] = a[i];
		else
			return dp[i][j][turn] = -a[i];
	}
	if(dp[i][j][turn] != -1)
		return dp[i][j][turn];
	if(turn == 0)
		return dp[i][j][turn] = max(fx(i+1, j, turn^1) + a[i], fx(i, j-1, turn^1) + a[j]);
	else
		return dp[i][j][turn] = min(fx(i+1, j, turn^1) - a[i], fx(i, j-1, turn^1) - a[j]);
}	
int main()
{
	ios_base::sync_with_stdio(false);
	ll i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<3002;i++)
		for(j=0;j<3002;j++)
			dp[i][j][0] = dp[i][j][1] = -1;
	cout<<fx(0, n-1, 0)<<nl;
	return 0;
}