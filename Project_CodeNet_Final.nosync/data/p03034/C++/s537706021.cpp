#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define REP(NAME, NUM) for (int NAME = 0; NAME < (NUM); ++NAME)
#define BREP(NAME, NUM) for (int NAME = (NUM)-1; NAME >= 0; --NAME)
#define ALL(NAME) (NAME).begin(), (NAME).end()
 
#define cMOD 1000000007ULL
#define cINF ((1ull<<62)-1)
#define cINFINT ((1<<30)-1)
 
inline ll score( const vector<ll>& s, ll a, ll b, ll n )
{
	ll cur = 0;
	ll ret = 0;
	while( cur < n )
	{
		cur += a;
		ret += s[cur];
		if( cur == n - 1 ) break;
		cur -= b;
		ret += s[cur];
	}
	return ret;
}
 
template <typename T>
inline vector<T> divisor( T n )
{
	vector<T> res;
	for( T i = 1; i * i <= n; ++i )
	{
		if( n % i == 0 )
		{
			res.push_back( i );
			if( i != n / i ) res.push_back( n / i );
		}
	}
	sort( ALL( res ) );
	return res;
}
 
template <typename T>
inline T gcd(T a, T b)
{
	if (a < b)
		swap(a, b);
	return b ? gcd(b, a % b) : a;
}
 
int main()
{
	ll n; cin >> n;
	vector<ll> s( n, 0 );
	REP(i,n) cin>>s[i];

	vector<vector<ll>> sum( 300, vector<ll>( n, 0 ) );
	REP(i,300) if( i != 0 ) REP(j,n)
	{
		if( j < i ) sum[i][j] = s[j];
		else sum[i][j] = s[j] + sum[i][j-i];
	}
	auto getSum = [sum]( ll start, ll end, ll step ) -> ll
	{
		if( start - step < 0 ) return sum[step][end];
		return sum[step][end] - sum[step][start - step];
	};
 
	ll ans = 0;
	REP( a, n )
	{
		if( a <= 2 || a == n - 1 ) continue;
		auto div = divisor<ll>( n - 1 - a );
		for( auto m : div )
		{
			ll b = a - ( n - 1 - a ) / m;
			//cout << a << " " << b << " " << m << " " << endl;
			if( a <= b || b <= 0 ) continue;
 
			// どぼん
			ll g = gcd<ll>( a, b );
			ll a_ = a / g;
			ll b_ = b / g;
			if( a_ == b_ + 1 && b_ < m ) continue;
 
			ll sc;
			if( a-b < 300 ) sc = getSum( a, n-1, a-b ) + getSum( a-b, n-1-a, a-b );
			else sc = score( s, a, b, n );
			//cout << a << " " << b << " " << sc << endl;
			ans = max( ans, sc );
		}
	}
	cout << ans << endl;
 
	return 0;
}