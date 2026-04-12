#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1000000007;
int main()
{
	ll sm=0;
	int n; cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; sm=(sm+a[i]);
	}
	ll ans=0;
	ll res=sm;
	ll act=0;
	for(int i=0;i<n-1;i++)
	{
		ll v=a[i];
		res-=a[i];
		act=res;
		act=(act%mod * v%mod ) %mod;
		ans=(ans+act)%mod;
	}
	cout<<ans;
}
	