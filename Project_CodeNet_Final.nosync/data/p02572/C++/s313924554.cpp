#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define prime 31
#define mp make_pair
#define INF 1000000000
#define mod 1000000007
#define fi first
#define se second
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	ll ans=0;
	ll dp[n+1]={0};
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
		dp[i+1]=dp[i]+arr[i];
	}
	for(ll i=1;i<n;i++)
	{
		ll x=(((dp[n]-dp[i]+mod)%mod)*(arr[i-1]%mod))%mod;
		ans=(ans+x)%mod;
	}
	cout<<ans<<endl;
}