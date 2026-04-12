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
const ll m = 1e9+7;
const ll N = 1e4+1;
vll k;
ll d;
ll nk;
ll dp[N][2][110];

ll go(ll x , ll small, ll sumi)
{
	if(x == nk)
	{
		return (sumi%d == 0) ? 1 : 0 ;
	}

	ll &ans = dp[x][small][sumi];
	if(ans != -1)
		return ans;
	ans = 0;

	if(small)
	{
		for(ll i = 0 ; i<=9 ; ++i)
		{
			ans += go(x+1 , small , (sumi+i)%d);
			ans %= m;
		}
	}
	else
	{
		for(ll i = 0 ; i<k[x] ; ++i)
		{
			ans += go(x+1 , small^1 , (sumi+i)%d);
			ans %=m;
		}

		ans += go(x+1 , small , (sumi+k[x])%d);
		ans%=m;

	}
	return (ans+m)%m;

}

signed main()
{

	fast;
	memset(dp , -1 , sizeof dp);
////////////////////////////////////////////////////////////////////////////////////////////
	
	string s;
	cin >> s;

	for(auto c: s)
	{
		ll a = c - '0';
		k.pb(a);
	}

	nk = k.size();

	cin >> d;

	cout<<(go(0 , 0 , 0) - 1 + m)%m<<endl;




////////////////////////////////////////////////////////////////////////////////////////////
	
	return 0;
}
