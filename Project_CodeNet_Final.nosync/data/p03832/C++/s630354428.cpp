#include <bits/stdc++.h>
#define For( i, j, k ) for( int i = j; i <= k; ++i )
#define Rep( i, j, k ) for( int i = j; i >= k; --i )
using std::pair;
using std::cin;
using std::cout;
using std::vector;
using std::make_pair;
const int mod = 1e9 + 7, N = 1007;
int n, A, B, C, D, f[ N ][ N ], fac[ N ], inv[ N ];
inline int POW( int a,int b )
{
 int ret = 1;
 for( ; b; b >>= 1, a = ( long long ) a * a % mod )
  if( b & 1 )
   ret = ( long long ) ret * a % mod; 
 return ret;
}
int main( )
{
 std::ios::sync_with_stdio( false );
 cin >> n >> A >> B >> C >> D;
 fac[ 0 ] = 1;
 For( i, 1, n )
  fac[ i ] = ( long long ) fac[ i - 1 ] * i % mod; 
/* cout << "fac\n";
 For( i, 0, n )
  cout << fac[ i ] << " ";*/
 inv[ n ] = POW( fac[ n ], mod - 2 );
// cout << inv[ n ];
 Rep( i, n - 1, 0 )
  inv[ i ] = ( long long ) ( i + 1 ) * inv[ i + 1 ] % mod;
/* cout << "\ninv\n";
 For( i, 0, n )
  cout << inv[ i ] << " ";*/
 f[ A - 1 ][ 0 ] = 1;
 For( i, A, B )
  For( j, 0, n )
  {
   int &F = f[ i ][ j ];
   F = f[ i - 1 ][ j ];
   for( int k = C, g = POW( inv[ i ], C ); k <= D && k * i <= j; ++k, g = ( long long ) g * inv[ i ] % mod )
   {
//    cout << g << " ";
    int u = n - j + k * i;
    F = ( F + ( long long ) f[ i - 1 ][ j - k * i ] * fac[ u ] % mod * inv[ k * i ] % mod * inv[ u - k * i ] % mod * fac[ k * i ] % mod * g % mod * inv[ k ] % mod ) % mod;
   }
  }
 cout << f[ B ][ n ];
 return 0;
}