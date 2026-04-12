#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int n;
	cin >> n;
	vector<int> a( n );
	for( auto& v: a ) { cin >> v; }

	int q;
	cin >> q;
	while( q-- > 0 ) {
		int k;
		cin >> k;
		cout << lower_bound( a.begin(), a.end(), k ) - a.begin() << '\n';
	}

	return 0;
}

