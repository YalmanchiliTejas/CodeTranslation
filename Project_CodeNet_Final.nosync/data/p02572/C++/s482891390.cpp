#include<bits/stdc++.h>

#define ll long long

const ll mod = 1000000007 ;

using namespace std ;

int main()
{
	ll n;
	cin>>n;
	ll A[n];
	for(ll i=0 ; i<n ; i++)
		cin>>A[i];
	vector<ll> v;
	ll sum = 0;
	for(ll i=0 ; i<n ; i++)
		sum+=A[i];
	ll ans = 0 ;
	for(ll i=0 ; i<n ; i++)
	{
		sum-=A[i];
		ans = (ans+((long long)A[i]*(sum%mod)%mod))%mod;
	}
	cout<<ans%mod;
}
