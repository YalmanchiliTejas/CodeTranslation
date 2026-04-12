#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a[3001];
ll dp[3001][3001];

ll func(ll i,ll j)
{
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i==j)
	{
		dp[i][j]=a[i];
		return dp[i][j];
	}
	if(j==i+1)
	{
		dp[i][j]=max(a[i],a[j]);
		return dp[i][j];
	}
	if(dp[i][j]!=-1)
		return dp[i][j];
	dp[i][j] = max(a[i]+min(func(i+2,j),func(i+1,j-1)),a[j]+min(func(i+1,j-1),func(i,j-2)));
	return dp[i][j];
}


int main()
{
	ios::sync_with_stdio(0);
	ll n,i,j;
	cin >> n;
	ll sum=0;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	for(i=0;i<=3000;i++)
	{
		for(j=0;j<=3000;j++)
			dp[i][j]=-1;
	}
	ll ans = func(0,n-1);
	ll y = sum-ans;
	cout << ans-y << "\n";
	return 0;
}