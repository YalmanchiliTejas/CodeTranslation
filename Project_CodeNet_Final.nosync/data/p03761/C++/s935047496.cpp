#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio( false );

	int n;
	cin >> n;

	vector<string> S( n );
	for( auto& v: S ) { cin >> v; }

	vector<vector<int>> cm( n, vector<int>(256) );
	for( int i = 0; i < n; ++i ) {
		for( auto ch: S[i] ) { cm[i][ch] += 1; }
	}

	for( char i = 'a'; i <= 'z'; ++i ) {
		int x = INT_MAX;

		for( int j = 0; j < n; ++j ) {
			if( cm[j][i] < x ) {
				x = cm[j][i];
			}
		}

		while( x-- ) {
			cout << i;
		}
	}

	cout << endl;
}
