/*

Author: @karngyan
Team: BlundersPride

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;
typedef std::pair<ll,ll> pll;
typedef std::vector<vll> vvll;

#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rrep(i,a,b) for(ll i=a;i>b;--i)
#define max3( a, b, c ) max( a , max(b , c))
#define cres(c,n) (c).clear(),(c).resize(n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ff first
#define ss second
#define mk make_pair
const ll N = 3e3+10;
vll a;
deque<ll> d;

signed main()
{
	fast;
////////////////////////////////////////////////////////////////////////////////////////////
	
	ll n;
	cin >> n;

	rep(i,0,n)
	{
		ll x;
		cin >> x;
		a.pb(x);

		ll k = a.size();
		while(k >= 3 and a[k-2] >= a[k-1] and a[k-2] >= a[k-3])
		{
			ll nawa = a[k-1]+a[k-3]-a[k-2];
			rep(i,0,3)
				a.pop_back();
			a.pb(nawa);
			k-=2;
		}
	}

	for(auto it: a)
		d.pb(it);

	ll ans = 0;
	ll sign = 1;
	while(d.size()!=0)
	{
		if(d.front()>=d.back())
		{
			ans+=sign*d.front();
			d.pop_front();
		}
		else
		{
			ans+=sign*d.back();
			d.pop_back();
		}
		sign*=-1;
	}
	cout<<ans<<endl;


	
	return 0;
}
