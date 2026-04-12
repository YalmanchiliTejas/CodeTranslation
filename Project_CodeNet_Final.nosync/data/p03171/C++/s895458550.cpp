#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define md 1000000007
#define mx 1e18
#define pb push_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<ll int,ll int>
#define ff first
#define ss second


int main()
{
	ll int n;
	cin>>n;

	ll int ts=0;

	ll int ar[n+1];
	for(ll int i=1;i<=n;i++)
	{
		cin>>ar[i];
		ts+=ar[i];
	}

	ll int dp[n+1][n+1];
	for(ll int i=0;i<=n;i++)
		for(ll int j=0;j<=n;j++)
			dp[i][j]=0;

	for(ll int i=1;i<=n;i++)
		dp[i][i]=ar[i];

	for(ll int i=n-1;i>=1;i--)
	{
		for(ll int j=i;j<=n;j++)
		{
			dp[i][j]=max(ar[i]+min(dp[i+2][j],dp[i+1][j-1]),ar[j]+min(dp[i+1][j-1],dp[i][j-2]));
		}
	}	

	ll int x=dp[1][n];

	cout<<(2*x)-ts<<endl;

	return 0;
}
