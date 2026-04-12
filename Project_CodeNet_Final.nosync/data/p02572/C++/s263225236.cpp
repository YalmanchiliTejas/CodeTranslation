#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main()
{
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;++i)	cin>>a[i];
	ll p[n];
	p[n-1] = 0;
	for(ll i=n-2;i>=0;--i)	p[i] = (p[i+1] + a[i+1])%mod;
	ll ans=0;
	for(ll i=0;i<n;++i)
	{
		ans = (ans%mod + ((a[i]%mod)*(p[i]%mod))%mod)%mod;
	}

	cout<<ans<<endl;
}	