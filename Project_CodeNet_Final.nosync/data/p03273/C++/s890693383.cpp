#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> a( H );
	for( int i = 0; i < H; i++ ) {
		cin >> a[i];
	}

	vector<int> v( H );
	vector<int> h( W );
	for( int i = 0; i < H; i++ ) {
		for( int j = 0; j < W; j++ ) {
			if( a[i][j] == '#' ) {
				v[i] = 1;
				h[j] = 1;
			}
		}
	}

	for( int i = 0; i < H; i++ ) {
		if( v[i] == 0 ) continue;
		for( int j = 0; j < W; j++ ) {
			if( h[j] == 0 ) continue;
			cout << a[i][j];
		}
		cout << endl;
	}
}
