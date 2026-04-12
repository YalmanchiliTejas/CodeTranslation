#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test() int t;cin>>t;for(int test=1;test<=t;test++)
#define pb push_back
#define nl cout<<"\n"
#define F first
#define S second
#define all(x) x.begin(),x.end()

template<class C> void min_self( C &a, C b ){ a = min(a,b); }
template<class C> void max_self( C &a, C b ){ a = max(a,b); }

const ll MOD = 1000000007;
ll mod( ll n, ll m=MOD ){ n%=m,n+=m,n%=m;return n; }

const int MAXN = 1e5+5;
const int LOGN = 21;
const ll INF = 1e14;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

template<class T1, class T2> void add( T1 &x, T2 y, ll m = MOD )
{
	x += y;
	if( x >= m )
		x -= m;
}

template<class T1, class T2> void sub( T1 &x, T2 y, ll m = MOD )
{
	x -= y;
	if( x < 0 )
		x += m;
}

int main() 
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	fastio();

	// a1 = x
	// a2 = x^2 mod m	
	// a3 = x^4 mod m
	// a4 = x^8 mod m
	// a5 = x^16 mod m
	// an = x^(2^(n-1)) mod m
	// sum of an = sum of ( x ^ 2^(i-1) ) mod m  for i = 1 to n

	ll n,x,m;
	cin>>n>>x>>m;

	
	vector<ll>v;
	set<ll>st;
	ll now = x;
	while( st.count(now) == 0 )
	{
		v.pb(now);
		st.insert(now);
		now = mod( now*now, m );
	}

	ll cycle_at = now;
	int sz = v.size(), index = -1;
	vector<ll>pref(sz+1,0);
	for(int i=0;i<sz;i++)
	{
		pref[i+1] = pref[i] + v[i];
		if( v[i] == now )
		{
			if( index == -1 )
				index = i;
		}
	}

	ll ans = pref[index];
	n -= index;

	int cycle_length = (sz-index);
	ll full = n/cycle_length;
	ll rem = n%cycle_length;

	ans += full * ( pref[sz] - pref[index] );
	ans += ( pref[index+rem] - pref[index] );

	cout<<ans,nl;


	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	return 0;
}
