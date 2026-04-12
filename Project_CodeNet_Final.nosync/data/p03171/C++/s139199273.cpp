#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ld long double
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define rloop(i,a,b) for(ll i=a;i>=b;i--)
const int inf=1e9+7;

int main()
{
	ll n;
	cin>>n;
	ll a[n];
	loop(i,0,n)
	{
		cin>>a[i];
	}
	vector< vector<ll> > dp(n,vector<ll>(n,0));
	loop(i,0,n) dp[i][i]=a[i];
	loop(k,1,n)
	{
		loop(i,0,n-k)
		{
			dp[i][i+k]=max(a[i]-dp[i+1][i+k],a[i+k]-dp[i][i+k-1]);
		}
	}
	cout<<dp[0][n-1];
	return 0;
}


