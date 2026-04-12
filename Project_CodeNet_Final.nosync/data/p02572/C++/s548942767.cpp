#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#define ll  long long int
#define mod 1000000007
using namespace std;

main()
{
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin>>a[i];
	ll ans=0;
	ll suff[n];
	suff[n-1]=0;
	for(ll i=n-2;i>=0;i--)
	{
		suff[i]=suff[i+1]+a[i+1];
		suff[i]=suff[i]%mod;
	}
	for(ll i=0;i<n;i++)
	{
		ll is = suff[i]*a[i];
		is%=mod;
		ans+=is;
		ans%=mod;
	}
	while(ans<0)
	{
		ans+=mod;
	}
	ans = (ans%mod);
	cout<<ans<<endl;
		
}