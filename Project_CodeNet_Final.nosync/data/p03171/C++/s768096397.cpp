#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define n 3005
ll mod=1e9+7;
ll N;
ll a[n];
ll dp[n][n];
ll DP(ll i,ll j)
{
	if (j<i)
		return 0;
	if (dp[i][j]!=-1)
		return dp[i][j];
	bool flg=(N-(j-i+1))%2;
	if (flg)
	{
		dp[i][j]= min(DP(i+1,j)-a[i],DP(i,j-1)-a[j]);
	}
	else
	{
		dp[i][j]=max(DP(i+1,j)+a[i],DP(i,j-1)+a[j]);
	}
	return dp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(ll i=0;i<N;i++)
		cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<DP(0,N-1);
}