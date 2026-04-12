#include <bits/stdc++.h>

#define int             long long
#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define REP( i, n )     FOR( i, 0, n )
#define REPR( i, m )    for( int (i) = (m); (i) >= 0; (i)-- )
#define REPONE( i, n )  FOR( i, 1, n + 1 )
#define ALL( a )        (a).begin(), (a).end()
#define MP              make_pair

using namespace std;
using P = pair<int, int>;

template<class T>bool chmax( T& a, const T& b ) { if( a < b ) { a = b; return 1; } return 0; }
template<class T>bool chmin( T& a, const T& b ) { if( a > b ) { a = b; return 1; } return 0; }

const int INF = 1e18;
const int MOD = 1e9 + 7;

signed main(){
    int N; cin >> N;
    vector<int> h( N );
    REP( i, N ) cin >> h[i];

    int t = h[0], ans = 1;
    REP( i, N - 1 ){
        if( h[i + 1] >= t ) ans++;
        chmax( t, h[i + 1] );
    }

    cout << ans << endl;
}