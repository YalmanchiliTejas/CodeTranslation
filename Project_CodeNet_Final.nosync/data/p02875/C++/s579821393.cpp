#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;
const int mod = 998244353;
inline int pls( int a , int b ) { a += b - mod; return a + ( a >> 31 & mod ); }
inline int mns( int a , int b ) { a -= b; return a + ( a >> 31 & mod ); }
inline void inc( int & a , int b ) { a += b - mod; a += a >> 31 & mod; }
inline void dec( int & a , int b ) { a -= b; a += a >> 31 & mod; }
inline int fpow( int b , int k ) {
  int res = 1;
  while( k ) {
    if( k & 1 ) res = 1LL * res * b % mod;
    b = 1LL * b * b % mod; k >>= 1;
  }
  return res;
} int _w;

int n , fac[N] , ifac[N] , Pow[N] , inv[N] , ans;

int binom( int n , int m ) { return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

int main( void ) {
  _w = scanf("%d",&n);
  fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1 , Pow[1] = 2;
  for( int i = 2 ; i <= n ; ++i ) {
    fac[i] = 1LL * fac[i - 1] * i % mod;
    inv[i] = 1LL * ( mod - mod / i ) * inv[mod % i] % mod;
    ifac[i] = 1LL * ifac[i - 1] * inv[i] % mod;
    Pow[i] = pls( Pow[i - 1] , Pow[i - 1] );
  }
  ans = fpow( 3 , n );
  for( int i = n / 2 + 1 ; i <= n ; ++i )
    dec( ans , 1LL * binom( n , i ) * Pow[n - i + 1] % mod );
  cout << ans;
  return 0;
}
