#include <bits/stdc++.h>
using namespace std;

#define int				long long
#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define FORE( i, m, n ) FOR( i, m , n + 1 )
#define REP( i, n )     FOR( i, 0, n )
#define REPE( i, n )	FOR( i, 0, n + 1 )
#define REPR( i, m )	for( int (i) = (m); (i) >= 0; (i)-- )
#define REPONE( i, n )	FOR( i, 1, n + 1 )
#define ALL( a )        (a).begin(), (a).end()
#define P				pair<string, int>
#define fi				first
#define se				second

template<class T>bool chmax( T& a, const T& b ) { if( a < b ) { a = b; return 1; } return 0; }
template<class T>bool chmin( T& a, const T& b ) { if( a > b ) { a = b; return 1; } return 0; }

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int MAX_N = 100;

bool G[MAX_N][MAX_N];

signed main() {
	int r, g, b; cin >> r >> g >> b;

	if( ( r * 100 + g * 10 + b ) % 4 == 0 ) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
}