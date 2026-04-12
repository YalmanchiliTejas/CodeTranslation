#include <bits/stdc++.h>
using namespace std;

const int MAXN = int( 2e5 );

int N;
int X[ MAXN ], Y[ MAXN ];

signed main() {
  ios::sync_with_stdio( 0 );
  cin >> N;
  for( int i = 0; i < N; ++i ) {
    cin >> X[ i ] >> Y[ i ];
  }
  long long ans = 1LL * 1e18;
  int mine = min( *min_element( X, X + N ), *min_element( Y, Y + N ) );
  int maxe = max( *max_element( X, X + N ), *max_element( Y, Y + N ) );
  { // case 1
    int max_min = 0, min_max = int( 1e9 ) ;
    for( int i = 0; i < N; ++i ) {
      max_min = max( max_min, min( X[ i ], Y[ i ] ) );
      min_max = min( min_max, max( X[ i ], Y[ i ] ) );
    }
    ans = 1LL * ( max_min - mine ) * ( maxe - min_max );
  }
  { // case2
    priority_queue< pair< int, int > > pq;
    multiset< int > bag;
    for( int i = 0; i < N; ++i ) {
      pq.emplace( -min( X[ i ], Y[ i ] ), max( X[ i ], Y[ i ] ) );
      bag.emplace( min( X[ i ], Y[ i ] ) );
    }
    ans = min( ans, 1LL * ( maxe - mine ) * ( *--bag.end() - *bag.begin() ) );
    for( int i = 0; i < N; ++i ) {
      int s, t;
      tie( s, t ) = pq.top();
      pq.pop();
      bag.erase( bag.find( -s ) );
      bag.emplace( t );
      ans = min( ans, 1LL * ( maxe - mine ) * ( *--bag.end() - *bag.begin() ) );
    }
  }
  cout << ans << endl;
  return 0;
}
