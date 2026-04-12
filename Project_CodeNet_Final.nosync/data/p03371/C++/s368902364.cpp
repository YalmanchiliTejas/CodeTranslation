#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio( false );

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int n = max( X, Y );
	int result = INT_MAX;
	for( int i = 0; i <= n; ++i ) {
		int p = 2*C*i + A*max( X-i, 0 ) + B*max( Y-i, 0 );

		if( p < result ) {
			result = p;
		}
	}

	cout << result << endl;

	return 0;
}
