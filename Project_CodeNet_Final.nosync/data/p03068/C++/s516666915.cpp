#include "bits/stdc++.h"
using namespace std;

#define FOR( i, m, n )	for( int (i) = (m); (i) < (n); i++ )
#define REP( i, n )		FOR( i, 0, n )
#define ALL( x )		(x).begin(), (x).end()

int main() {
	int n; cin >> n;

	string s; cin >> s;

	int k; cin >> k;
	int tmp = s[k - 1];
	REP( i, n ) {
		if( s[i] != tmp ) s[i] = '*';
	}

	cout << s <<endl;
}