#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
#include<unordered_map>
using namespace std ;

#define MOD 1000000007
#define MAXN 1007

int n ;
int mng , mxg ;
int lo , hi ;

long long dp[ MAXN ][ MAXN ] ;

long long fac[ MAXN ] ;
long long inv[ MAXN ] ;


long long fastpow ( long long x , long long pw ) {
    long long ret = 1 ;
    while ( pw > 0 ) {
        if ( ( pw & 1 ) == 0 ) {
            x = ( x * x ) % MOD ;
            pw /= 2 ;
        }
        else {
            ret = ( ret * x ) % MOD ;
            -- pw ;
        }
    }
    return ret ;
}

void input ( ) {
    cin >> n >> mng >> mxg >> lo >> hi ;
}

void solve ( ) {
    fac[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
    }
    inv[ n ] = fastpow ( fac[ n ] , MOD - 2 ) ;
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        inv[ i ] = ( inv[ i + 1 ] * ( i + 1 ) ) % MOD ;
    }

    dp[ mng - 1 ][ n ] = 1 ;
    for ( int i = mng ; i <= mxg ; ++ i ) {
        long long hh = fastpow ( inv[ i ] , lo ) ;
        for ( int j = 0 ; j <= n ; ++ j ) {
            dp[ i ][ j ] = dp[ i - 1 ][ j ] ;
            long long coef = hh ;
            for ( int t = lo ; t <= hi ; ++ t ) {
                if ( t * i + j > n ) { break ; }
                long long ways = ( fac[ t * i + j ] * inv[ j ] ) % MOD ;
                ways = ( ways * coef ) % MOD ;
                ways = ( ways * inv[ t ] ) % MOD ;
                dp[ i ][ j ] += ( ways * dp[ i - 1 ][ t * i + j ] ) % MOD ;
                dp[ i ][ j ] %= MOD ;
                coef = ( coef * inv[ i ] ) % MOD ;
            }
        }
    }
    printf ( "%lld\n" , dp[ mxg ][ 0 ] ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}
