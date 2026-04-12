#include<bits/stdc++.h>
using namespace std ;
#define rep(i,s,t )for(register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
    char cc = getchar() ; int cn = 0, flus = 1 ;
    while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
    while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
    return cn * flus ;
}
const int P = 998244353 ; 
const int N = 1e7 + 5 ;
int n, inv[N], fac[N], fp[N], Ans ;
int fpow( int x, int k ) {
    int ans = 1, base = x ;
    while( k ) {
        if( k & 1 ) ans = ans * base % P ;
        base = base * base % P, k >>= 1 ;
    } return ans ; 
}
void inc( int &x, int y ) {
    ( ( x += y ) >= P ) && ( x -= P ) ;
}
int C( int x, int y ) {
    if( y > x ) return 0 ;
    return fac[x] * inv[y] % P * inv[x - y] % P ;
}
signed main()
{
    n = gi(), fp[0] = inv[0] = fac[0] = 1 ;
    rep( i, 1, n ) fac[i] = fac[i - 1] * i % P, fp[i] = fp[i - 1] * 2 % P ; 
    inv[n] = fpow( fac[n], P - 2 ) ;
    for( re int i = n; i >= 1; -- i ) inv[i - 1] = inv[i] * i % P ;
    int m = ( n / 2 ) + 1, num = 0 ;
    Ans = fpow( 3, n ) ;
    for( re int i = m; i <= n; ++ i ) {
        int dec = C( n, i ) ;
        dec = dec * fp[n - i] % P ;
        inc( num, dec ) ;
    }
    Ans = ( Ans - num * 2ll % P + P ) % P ;
    printf("%lld\n", Ans ) ;
    return 0 ;
}