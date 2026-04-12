#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;

	vector<vector<char>> a( H, vector<char>(W) );

	for( int i = 0; i < H; ++i ) {
		for( int j = 0; j < W; ++j ) {
			cin >> a.at( i ).at( j );
		}
	}

	for( int row = H-1; row >= 0; --row ) {
		int black = 0;

		for( int col = 0; col < W; ++col ) {
			if( a.at( row ).at( col ) == '#' ) {
				black++;
			}
		}

		if( black == 0 ) {
			a.erase( a.begin() + row );
		}
	}

	for( int col = W-1; col >= 0; --col ) {
		int black = 0;

		for( int row = 0; row < a.size(); ++row ) {
			if( a.at( row ).at( col ) == '#' ) {
				black++;
			}
		}

		if( black == 0 ) {
			for( int row = 0; row < a.size(); ++row ) {
				a.at( row ).erase( a.at( row ).begin() + col );
			}
		}
	}

	for( auto&& r: a ) {
		for( auto&& c: r ) {
			cout << c;
		}

		cout << endl;
	}
}
