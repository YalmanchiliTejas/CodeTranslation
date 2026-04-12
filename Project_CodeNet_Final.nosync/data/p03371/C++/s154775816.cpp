#include <bits/stdc++.h>

#define int             long long
#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define REP( i, n )     FOR( i, 0, n )
#define REPR( i, m )    for( int (i) = (m); (i) >= 0; (i)-- )
#define ALL( a )        (a).begin(), (a).end()
#define MP              make_pair

using namespace std;
using P = pair<int, int>;

template<class T>bool chmax( T& a, const T& b ) { if( a < b ) { a = b; return 1; } return 0; }
template<class T>bool chmin( T& a, const T& b ) { if( a > b ) { a = b; return 1; } return 0; }

const int INF = 1e18;
const int MOD = 1e9 + 7;

signed main(){
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

    int sum = 0;
    sum += min( a + b, 2 * c ) * min( x, y );
    if( x < y ) sum += min( b, 2 * c ) * ( y - x );
    if( x > y ) sum += min( a, 2 * c ) * ( x - y );

    cout << sum << endl;
}
