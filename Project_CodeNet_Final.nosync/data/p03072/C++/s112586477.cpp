#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	while ( cin >> n ) {
		int h[ n+5 ], mh[ n+5 ]; mh[0] = 0;
		
		for (int i = 1; i <= n; ++i) { cin >> h[i]; mh[i] = max( mh[ i-1 ], h[i] ); }
		
		int ans = 0;
		
		for (int i = 1; i <= n; ++i) if ( h[i] == mh[i] ) ans++ ;
		
		cout << ans << '\n';
	}
	return 0;
}