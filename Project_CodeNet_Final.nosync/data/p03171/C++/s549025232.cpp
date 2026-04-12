#include<iostream>
#include<climits>
#include<cmath>
#include<functional>

using namespace std;

int main() {
   int N;
   cin >> N;
   int a[ N ];
   long long total = 0;
   for( int i = 0; i < N; i++ ) {
      cin >> a[ i ];
      total += a[ i ];
   }

   long long *** dp = ( long long *** ) malloc( sizeof( long long *** ) * 2 );
   for( int i = 0; i < 2; i++ ) {
      dp[ i ] = ( long long ** ) malloc( sizeof( long long ** ) * N );
      for( int j = 0; j < N; j++ ) {
         dp[ i ][ j ] = ( long long * ) malloc( sizeof( long long * ) * N );
         for( int k = 0; k < N; k++ ) {
            dp[ i ][ j ][ k ] = LONG_MAX;
         }
      }
   }

   function< long long( int, int, int )> getDp;

   getDp = [ & ]( int t, int i, int j ) -> long long {
      if( i == j ) {
         return t == 0 ? a[ i ] : 0;
      }
      if( dp[ t ][ i ][ j ] != LONG_MAX ) {
         return dp[ t ][ i ][ j ];
      }
      auto val1 = getDp( 1 - t, i + 1, j );
      auto val2 = getDp( 1 - t, i, j - 1 );
      if( t == 0 ) {
         if( val1 + a[ i ] > val2 + a[ j ] ) {
            dp[ t ][ i ][ j ] = a[ i ] + val1 ;
         } else {
            dp[ t ][ i ][ j ] = a[ j ] + val2 ;
         }
      } else {
         dp[ t ][ i ][ j ] = min( val1, val2 );
      }
      return dp[ t ][ i ][ j ];
   };
   auto x = getDp( 0, 0, N - 1 );
   cout << ( x - total + x );
   return 0;
}
