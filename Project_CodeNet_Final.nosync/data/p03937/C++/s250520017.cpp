#include<bits/stdc++.h>

using namespace std;

int main() {
	long long int H, W;
	cin >> H >> W;
	vector<string>D( H );
	for( size_t i = 0; i < H; i++ ) {
		cin >> D[i];
	}
	for( size_t i = 0; i < H; i++ ) {
		for( size_t j = 0; j < W; j++ ) {
			if( D[i][j] == '#' ) {
				for( size_t k = i + 1; k < H; k++ ) {
					for( size_t l = 0; l < j; l++ ) {
						if( D[k][l] == '#' ) {
							cout << "Impossible" << endl;
							return 0;
						}
					}
				}
			}
		}
	}
	cout << "Possible" << endl;
}