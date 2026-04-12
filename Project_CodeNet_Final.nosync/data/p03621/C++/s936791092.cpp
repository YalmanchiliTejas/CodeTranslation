#include <cstdio>

const int mod = 998244353;
const int MAXN = 10005;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

int f[MAXN][MAXN];
int fac[MAXN], ifac[MAXN];
char A[MAXN], B[MAXN];
int N;

int qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = 1ll * ret * base % mod;
		base = 1ll * base * base % mod, indx >>= 1;
	}
	return ret;
}

void init( const int siz )
{
	fac[0] = 1;
	for( int i = 1 ; i <= siz ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[siz] = qkpow( fac[siz], mod - 2 );
	for( int i = siz - 1 ; ~ i ; i -- ) ifac[i] = 1ll * ifac[i + 1] * ( i + 1 ) % mod;
}

int C( const int n, const int m ) 
{ 
	if( n < m || n < 0 || m < 0 ) return 0;
	return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }

int main()
{
	int S = 0, T = 0;
	scanf( "%s%s", A + 1, B + 1 );
	for( N = 1 ; A[N] ; N ++ )
	{
		int a = A[N] - '0', b = B[N] - '0';
		if( a && b ) S ++;
		if( a && ! b ) T ++;
	}
	init( N );
	f[0][0] = 1;
	for( int i = 0 ; i <= S ; i ++ )
		for( int j = 0 ; j <= T ; j ++ )
		{
			if( i ) add( f[i][j], 1ll * f[i - 1][j] * i % mod * j % mod );
			if( j ) add( f[i][j], 1ll * f[i][j - 1] * j % mod * j % mod );
		}
	int ans = 0;
	for( int i = 0 ; i <= S ; i ++ )
		add( ans, 1ll * C( S + T, i ) * C( S, i ) % mod * fac[i] % mod * fac[i] % mod * f[S - i][T] % mod );
	write( ans ), putchar( '\n' );
	return 0;
}