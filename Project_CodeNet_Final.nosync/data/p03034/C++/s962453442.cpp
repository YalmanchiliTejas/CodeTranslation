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

	vector<vector<ll>> dp(n, vector<ll>());
	REP(i,n) if( i >= 1 )
	{
		dp[i].push_back( 0 );
		for( ll j = 1; j * i < n; ++j )
		{
			auto sum = s[i*j] + s[n-1-i*j] + dp[i][j-1];
			dp[i].push_back( sum );
		}
	}
 
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
 
			ll sc = dp[a-b][m];
			//cout << a << " " << b << " " << sc << endl;
			ans = max( ans, sc );
		}
	}
	cout << ans << endl;
 
	return 0;
}