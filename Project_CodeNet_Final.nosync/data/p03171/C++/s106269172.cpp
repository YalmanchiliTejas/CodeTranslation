#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)cin>>a[i];
	ll dp[n][n];
	for(ll i=0;i<n;i++)dp[i][i]=a[i];
	for(ll l=2;l<=n;l++)
	{
		for(ll i=0;i<n-l+1;i++)
		{
			ll j=i+l-1;
			dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	}
	cout<<dp[0][n-1]<<endl;
	return 0;
}