#include <cstdio>
#include <cstring>

const int MAXL = 1e4, MOD = 998244353;
int n, sur, bal, f[MAXL + 5][MAXL + 5];
int fac[MAXL + 5], ifac[MAXL + 5];
char A[MAXL + 5], B[MAXL + 5];

inline void addeq ( int& a, const int b ) { if ( ( a += b ) >= MOD ) a -= MOD; }
inline int mul ( long long a, const int b ) { return ( a *= b ) < MOD ? a : a % MOD; }

inline int qkpow ( int a, int b ) {
	int ret = 1;
	for ( ; b; a = 1ll * a * a % MOD, b >>= 1 ) ret = 1ll * ret * ( b & 1 ? a : 1 ) % MOD;
	return ret;
}

inline void init () {
	fac[0] = 1;
	for ( int i = 1; i <= n; ++ i ) fac[i] = mul ( i, fac[i - 1] );
	ifac[n] = qkpow ( fac[n], MOD - 2 );
	for ( int i = n - 1; ~ i; -- i ) ifac[i] = mul ( i + 1, ifac[i + 1] );
}

inline int comb ( const int n, const int m ) {
	return n < m ? 0 : mul ( fac[n], mul ( ifac[m], ifac[n - m] ) );
}

int main () {
	scanf ( "%s %s", A + 1, B + 1 );
	n = strlen ( A + 1 ), init ();
	for ( int i = 1; i <= n; ++ i ) {
		if ( A[i] ^ '0' && B[i] ^ '0' ) ++ bal;
		else if ( A[i] > B[i] ) ++ sur;
	}
	f[0][0] = 1;
	for ( int i = 0; i <= bal; ++ i ) {
		for ( int j = 0, cur; j <= sur; ++ j ) {
			if ( ! ( cur = f[i][j] ) ) continue;
			addeq ( f[i + 1][j], mul ( cur, mul ( i + 1, j ) ) );
			addeq ( f[i][j + 1], mul ( cur, mul ( j + 1, j + 1 ) ) );
		}
	}
	int ans = 0;
	for ( int i = 0; i <= bal; ++ i ) {
		int fre = bal - i;
		int self = mul ( mul ( fac[fre], fac[fre] ),
			mul ( comb ( bal + sur, fre ), comb ( bal, fre ) ) );
		addeq ( ans, mul ( f[i][sur], self ) );
	}
	printf ( "%d\n", ans );
	return 0;
}