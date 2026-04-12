#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <stack>
#include <queue>
#include <tuple>
#include <regex>
#include <cmath>
#include <map>
#include <set>
#include <functional>
#include <cstring>

using namespace std;

template<typename T> bool chmax( T &a, const T b ) { if ( a <= b ) { a = b; return ( true ); } else { return ( false ); } }
template<typename T> bool chmin( T &a, const T b ) { if ( a >= b ) { a = b; return ( true ); } else { return ( false ); } }

using ll = long long;
using Pint = pair<int, int>;
using Pll  = pair<ll, ll>;

#define eb emplace_back
#define pb push_back
#define mp make_pair

#define F first
#define S second

#define popcnt __builtin_popcountll

#define rep( i, n ) for ( ll i = 0; i < (ll)( n ); ++i )
#define reps( i, n ) for ( ll i = 1; i <= (ll)( n ); ++i )
#define rrep( i, n ) for ( ll i = (ll)( ( n ) - 1 ); i >= 0; --i )
#define rreps( i, n ) for ( ll i = (ll)( ( n ) ); i > 0; --i )
#define arep( i, v ) for ( auto &&i : ( v ) )

#define ALL( c ) ( c ).begin(), ( c ).end()
#define RALL( c ) ( c ).rbegin(), ( c ).rend()
#define UNIQUE( c ) ( c ).erase( unique( ( c ).begin(), ( c ).end() ), ( c ).end() )

template<typename T = ll> constexpr T MAX = numeric_limits<T>::max();
template<typename T> T gcd( const T a, const T b ) { return ( b ? gcd( b, a % b ) : a ); }
template<typename T> T lcm( const T a, const T b ) { return ( a / gcd( a, b ) * b ); }


int main()
{
	ll n; cin >> n;
	vector<ll> a( n );
	rep( i, n ) cin >> a[i];

	constexpr ll inf = 1e18;
	vector<vector<ll>> dp( n + 1, vector<ll>( 10, -inf ) );
	rep( i, 3 ) if ( i < n ) dp[i][i] = a[i];
	rep( i, n )
	{
		rep( j, 3 )
		{
			for ( ll d = 0; j + d < 3; ++d )
			{
				ll pre = i - 2 - d;
				if ( pre < 0 ) continue;
				chmax( dp[i][j + d], dp[pre][j] + a[i] );
			}
		}
	}

	ll ans = -inf;
	ll dd = n % 2 + 1;
	rep( d, dd + 1 )
	{
		ll i = n - 1 - d;
		if ( i >= 0 ) chmax( ans, dp[i][dd - d] );
	}

	cout << ans << endl;

	return ( 0 );
}
