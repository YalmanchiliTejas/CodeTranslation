#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N = 5000;

int MOD;
int n, m;
ll g[N][N], f[N];
ll fac[N], inv_fac[N];

inline ll add( ll a, ll b ) {
	ll ret = a + b; 
	if( ret >= MOD ) ret -= MOD;
	if( ret < 0 ) ret += MOD;
	return ret;
}

ll C( int n, int m ) {
	return fac[n] * inv_fac[n-m] %MOD * inv_fac[m] %MOD;
}

inline ll ksm( ll a, ll b, ll mod ) {
	ll ret = 1;
	for( ; b; b >>= 1, a = a * a %mod )
		if( b & 1 ) ret = ret * a %mod;
	return ret;
}	

void calc_fac( int size )
{
	fac[0] = 1;
	for( int i = 1; i <= size; i ++ )
		fac[i] = fac[i-1] * i %MOD;
	
	for( int i = 0; i <= size; i ++ )
		inv_fac[i] = ksm( fac[i], MOD-2, MOD );
}

void calc_g()
{
	memset( g, 0, sizeof( g ) ); 
	for( int i = 0; i <= n; i ++ )
		g[i][0] = 1;
	
	for( int i = 1; i <= n; i ++ )
		for( int j = 1; j <= i; j ++ )
			g[i][j] = add( g[i-1][j-1], g[i-1][j] * ( j + 1 ) %MOD ); 
}

void calc_f()
{
	for( int i = 0; i <= n; i ++ )
	{
		ll tmp = ksm( 2, n-i, MOD ), tmp2 = 1;

		for( int j = 0; j <= i; j ++, tmp2 = tmp2 * tmp %MOD )
			f[i] = add( f[i], g[i][j] * tmp2 %MOD );
			
		tmp = ksm( 2, n-i, MOD-1 );
		f[i] = f[i] * ksm( 2, tmp, MOD ) %MOD;
	}
}

ll calc_ans() 
{
	ll ret = 0; int cur = 1;
	for( int i = 0; i <= n; i ++, cur = cur == 1 ? MOD-1 : 1 )
		ret = add( ret, C( n, i ) * f[i] %MOD * cur %MOD );
	return ret;
}

int main()
{
	scanf( "%d%d", &n, &MOD );
	
	calc_fac( n );
	calc_g();
	calc_f(); 
	
//	for( int i = 0; i <= n; i ++ )
//		printf( "%lld ", f[i] ); printf( "\n" );
	
	printf( "%d\n", calc_ans() );
	
	return 0;
}