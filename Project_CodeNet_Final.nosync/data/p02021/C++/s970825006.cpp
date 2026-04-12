#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

#define int				long long
#define FOR( i, m, n )  for( int (i) = (m); (i) < (n); (i)++ )
#define FORE( i, m, n ) FOR( i, m , n + 1 )
#define REP( i, n )     FOR( i, 0, n )
#define REPE( i, n )	FOR( i, 0, n + 1 )
#define FORR( i, m, n ) for( int (i) = (m); (i) >= 0; (i)-- )
#define ALL( a )        (a).begin(), (a).end()             
#define MP( a, b )		make_pair( (a), (b) )
#define fi				first
#define se				second

signed main() {
	int n; cin >> n;
	vector<int> a( n );

	REP( i, n ) cin >> a[i];

	int sum = 0, ans = INF;
	REP( i, n ) {
		sum += a[i];
		ans = min( sum / ( i + 1 ), ans );
	}

	cout << ans << endl;
}
