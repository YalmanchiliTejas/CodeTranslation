#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int H, W;
	cin >> H >> W;

	int x = 0;
	for( int i = 0; i < H; ++i ) {
		for( int j = 0; j < W; ++j ) {
			char ch;
			cin >> ch;

			x += (ch != '.');
		}
	}

	cout << (x == H+W-1 ? "Possible" : "Impossible") << endl;

	return 0;
}
