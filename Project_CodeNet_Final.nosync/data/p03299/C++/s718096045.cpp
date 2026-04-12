#include <vector>
#include <iostream>

#define mkpr make_pair

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100, MOD = 1e9 + 7;
int n, h[MAXN + 5];

inline int qkpow ( int a, int b, const int p = MOD ) {
	int ret = 1;
	for ( ; b; a = 1ll * a * a % p, b >>= 1 ) ret = 1ll * ret * ( b & 1 ? a : 1 ) % p;
	return ret;
}

inline pii solve ( const int l, const int r, const int cut ) {
	if ( l > r ) return mkpr ( 1, 0 );
	int height = 0x3f3f3f3f;
	for ( int i = l; i <= r; ++ i ) height = height < h[i] ? height : h[i];
	vector<int> lowpos; lowpos.push_back ( l - 1 );
	for ( int i = l; i <= r; ++ i ) if ( height == h[i] ) lowpos.push_back ( i );
	lowpos.push_back ( r + 1 );
	int lowcnt = ( int ) lowpos.size () - 2, prdfirst = 1, prdboth = 1;
	for ( int i = 0; i < ( int ) lowpos.size () - 1; ++ i ) {
		pii tmp ( solve ( lowpos[i] + 1, lowpos[i + 1] - 1, height ) );
		prdfirst = 1ll * prdfirst * tmp.first % MOD;
		prdboth = 1ll * prdboth * ( tmp.first + tmp.second ) % MOD;
	}
	int pwr = qkpow ( 2, height -= cut );
	return lowpos.clear (),
		   mkpr ( 1ll * pwr * prdfirst % MOD, ( 1ll * qkpow ( 2, lowcnt ) * prdboth % MOD + ( pwr - 2ll ) * prdfirst % MOD ) % MOD );
}

int main () {
	ios :: sync_with_stdio ( false );
	cin >> n;
	for ( int i = 1; i <= n; ++ i ) cin >> h[i];
	cout << ( solve ( 1, n, 0 ).second + MOD ) % MOD << endl;
	return 0;
}