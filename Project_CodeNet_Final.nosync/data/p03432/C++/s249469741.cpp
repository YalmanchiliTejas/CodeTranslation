#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "cmath"
#include "vector"
#include "map"
#include "set"
#include "queue"
using namespace std;
#define MAXN 200006
//#define int long long
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x) (x).begin() , (x).end()
#define mem( a ) memset( a , 0 , sizeof a )
typedef long long ll;
#define P 998244353
int n , m;
int A[MAXN];

int Pow( int x , int a ) {
	int ret = 1;
	while( a ) {
		if( a & 1 ) ret = ret * 1ll * x % P;
		x = 1ll * x * x % P , a >>= 1;
	}
	return ret;
}
int Wn[2][MAXN] , rev[MAXN];
void getwn( int len ) {
    for( int mid = 1 ; mid < len ; mid <<= 1 ) {
        int w0 = Pow( 3 , ( P - 1 ) / ( mid << 1 ) ) , w1 = Pow( 3 , P - 1 - ( P - 1 ) / ( mid << 1 ) );
        Wn[0][mid] = Wn[1][mid] = 1;
        for( int i = 1 ; i < mid ; ++ i )
            Wn[0][mid + i] = 1ll * Wn[0][mid + i - 1] * w0 % P,
            Wn[1][mid + i] = 1ll * Wn[1][mid + i - 1] * w1 % P;
    }
}
void getr( int len ) {
    int t = __builtin_ctz( len ) - 1;
    for( int i = 1 ; i < len ; ++ i ) rev[i] = ( rev[i >> 1] >> 1 ) | ( ( i & 1 ) << t );
}
void NTT( int* A , int len , int typ ) {
    rep( i , 0 , len - 1 ) if( i < rev[i] ) swap( A[i] , A[rev[i]] );
    for( int mid = 1 ; mid < len ; mid <<= 1 )
        for( int i = 0 ; i < len ; i += ( mid << 1 ) )
            for( int k = 0 ; k < mid ; ++ k ) {
                int t1 = A[i + k] , t2 = 1ll * A[i + k + mid] * Wn[typ][mid + k] % P;
                A[i + k] = (t1 + t2) % P , A[i + k + mid] = (t1 + P - t2) % P;
            }
    if( typ == 1 ) for( int inv = Pow( len , P - 2 ) , i = 0 ; i < len ; ++ i ) A[i] = 1ll * A[i] * inv % P;
}

int f[MAXN] , g[MAXN] , t[MAXN];
int J[MAXN] , iJ[MAXN];
int C( int a , int b ) {
	if( a < b ) return 0;
	return J[a] * 1ll * iJ[b] % P * iJ[a - b] % P;
}

int len;

void wkr( ) {
	rep( i , 0 , len - 1 ) f[i] = ( 1 + i + C( i , 2 ) ) % P * 1ll * g[i] % P , g[i] = g[i] * 1ll * iJ[i] % P;
	getr( len ) , getwn( len );
	NTT( g , len , 0 );
	rep( i , 0 , len - 1 ) g[i] = g[i] * 1ll * t[i] % P;
	NTT( g , len , 1 );
	rep( i , 0 , n ) f[i] += J[i + 2] * 1ll * g[i] % P , f[i] %= P;
	rep( i , n + 1 , len - 1 ) f[i] = 0;
	rep( i , 0 , len - 1 ) g[i] = f[i];
}

void solve() {
	cin >> n >> m;
	g[0] = 1;
	J[0] = iJ[0] = 1; rep( i , 1 , MAXN - 1 ) J[i] = J[i - 1] * 1ll * i % P , iJ[i] = Pow( J[i] , P - 2 );
	len = 1; while( len <= n + n ) len <<= 1;
	getr( len ) , getwn( len );
	t[0] = 0;
	rep( i , 1 , n ) t[i] = iJ[i + 2];
	NTT( t , len , 0 );
	rep( i , 1 , m ) wkr();
	int res = 0;
	rep( i , 0 , n ) 
		res += ( C( n , i ) * 1ll * f[i] % P ) , res %= P;
	cout << res << endl;
}

signed main() {
//    int T;cin >> T;while( T-- ) solve();
    solve();
}

