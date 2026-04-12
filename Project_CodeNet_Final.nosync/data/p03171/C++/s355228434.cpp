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
//MIT OCW DP PROBLEM
const ll N = 3010;
ll a[N];
ll dp[N][N];

ll go(ll i , ll j)
{
	if(i == j)
		return a[i];

	ll &ans = dp[i][j];
	if(ans != -1)
		return ans;

	ans = max( a[i] - go(i+1 , j) , a[j] - go(i, j-1));
	return ans;
}

signed main()
{

	fast;
	memset( dp , -1 , sizeof dp );
////////////////////////////////////////////////////////////////////////////////////////////
		
	ll n;
	cin >> n;
	ll tot = 0;
	rep(i,0,n)
		cin >> a[i];

	cout<<go(0 , n-1)<<endl;


	
	return 0;
}
