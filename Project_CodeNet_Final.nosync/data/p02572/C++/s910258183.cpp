#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll powr(ll a,ll b, ll mod)
{
	if(b<=0)
		return 1;
	else if(b%2==0)
	{
		ll x = powr(a,b/2,mod);
		return (x*x)%mod;
	}
	else
		return (a*powr(a,b-1,mod))%mod;
}
void solve()
{
	ll n,mod = 1e9 + 7;
	cin>>n;
	ll a[n];
	ll sum = 0;
	ll sq = 0 ;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum = (sum + a[i])%mod;
		sq = (sq + a[i]*a[i])%mod;
	}
	cout<<(((sum*sum)%mod-sq+mod)*powr(2,mod-2,mod))%mod<<endl;

}

int main()
{
	ll t = 1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
}