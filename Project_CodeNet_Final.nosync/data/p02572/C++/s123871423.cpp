#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld double
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define pll pair <ll,ll>
#define nl "\n"
ll poq(ll x, ll y, ll md)
{
	ll pro = 1;
	while(y)
	{
		if(y%2)
		{
			pro = (pro*x)%md;
		}
		x = (x*x)%md;
		y/=2;
	}
	return pro;
} 
int main()
{
	ios_base::sync_with_stdio(false);
	ll a=0,s=0,i,n;
	cin>>n;
	for(i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		a = (a + (x*x)%mod)%mod;
		s = (s + x)%mod;
	}
	s = (s*s)%mod;
	ll ans = (s-a+mod)%mod;
	ans = (poq(2, mod-2, mod) * ans)%mod;
	cout<<ans<<nl;
	return 0;
}