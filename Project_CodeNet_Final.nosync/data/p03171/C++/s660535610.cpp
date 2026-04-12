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

   /*long long *** dp = ( long long *** ) malloc( sizeof( long long *** ) * 2 );
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
   */

   // can be made better by considering only A and coputing B's outcome at A's
   // recursion
   // A: ( i, j )
   //             B: (i+1, j)
   //                            A: (i+2, j)
   //                            A: (i+1, j-1)
   //             B: (i, j-1 )
   //                            A:(i+1, j-1)
   //                            A:(i, j-2)
   long long ** dp2 = ( long long ** ) malloc( sizeof( long long ** ) * N );
   for( int i = 0; i < N; i++ ) {
      dp2[ i ] = ( long long * ) malloc( sizeof( long long * ) * N );
      for( int j = 0; j < N; j++ ) {
         dp2[ i ][ j ] = LONG_MAX;
      }
   }
   function< long long( int, int )> getDp2;
   getDp2 = [ & ]( int i, int j ) -> long long {
      if( i == j ) {
         return a[ i ];
      }
      if( i + 1 == j ) {
         return max( a[ i ], a[ j ] );
      }
      if( i + 2 == j ) {
         return max( a[ i ] + min( a[ i + 1 ], a[ j ] ),
                     min( a[ i ], a[ i + 1 ] ) + a[ j ] );
      }
      if( dp2[ i ][ j ] != LONG_MAX ) {
         return dp2[ i ][ j ];
      }
      //Computing B(i+1, j)
      auto x = min( getDp2( i + 2, j ), getDp2( i + 1, j - 1 ) );
      //Computing B(i, j-1)
      auto y = min( getDp2( i + 1, j - 1 ), getDp2( i, j - 2 ) );
      if( x + a[ i ] > y + a[ j ] ) {
         dp2[ i ][ j ] = x + a[ i ];
      } else {
         dp2[ i ][ j ] = y + a[ j ];
      }
      return dp2[ i ][ j ];
   };

   auto x = getDp2( 0, N - 1 );
   cout << ( x - total + x );
   return 0;
}
