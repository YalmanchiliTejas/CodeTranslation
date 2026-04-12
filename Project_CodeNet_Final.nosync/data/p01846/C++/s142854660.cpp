#include<bits/stdc++.h>
/*
*/

using namespace std;


int main() {
	while( true ) {
		string S;
		cin >> S;
		if( S == "#" ) {
			break;
		}
		vector<string>VS( 1 );
		for( size_t i = 0; i < S.length(); i++ ) {
			if( S[i] == '/' ) {
				VS.push_back( "" );
			} else if( S[i] == 'b' ) {
				VS[VS.size() - 1].push_back( 'b' );
			} else {
				for( size_t j = 0; j < S[i] - '0'; j++ ) {
					VS[VS.size() - 1].push_back( '.' );
				}
			}
		}
		long long int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		VS[a][b] = '.';
		VS[c][d] = 'b';
		for( size_t i = 0; i < VS.size(); i++ ) {
			int count = 0;
			for( size_t j = 0; j < VS[i].size(); j++ ) {
				if( VS[i][j] == 'b' ) {
					if( count ) {
						cout << count;
						count = 0;
					}
					cout << "b";
				} else {
					count++;
				}
			}
			if( count ) {
				cout << count;
			}
			if( i == VS.size() - 1 ) {
				cout << endl;
			} else {
				cout << "/";
			}
		}
	}
}