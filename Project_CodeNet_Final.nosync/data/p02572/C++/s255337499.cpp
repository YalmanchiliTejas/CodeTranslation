#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1e9+7;
int main()
{
	ll i,j,k,m,n,t;
	cin>>n;
	ll ar[n];
	for(i=0;i<n;i++)
	cin>>ar[i];
	ll suf[n];
	suf[n-1]=ar[n-1];
	for(i=n-2;i>=0;i--)
	{
		suf[i]=suf[i+1]+ar[i];
	}
	ll ans=0;
	for(i=0;i<n-1;i++)
	{
		ll x=ar[i]*(suf[i+1]%mod);
		x%=mod;
		ans+=x;
		ans%=mod;
	}
	cout<<ans;
}