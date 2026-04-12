#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> A( H );
	for( int i = 0; i < H; i++ ) {
		cin >> A[i];
	}

	int cnt = 0;
	for( int i = 0; i < H; i++ ) {
		for( int j = 0; j < W; j++ ) {
			if( A[i][j] == '#' ) cnt++;
		}
	}
	string ans = "Possible";
	if( cnt != H + W - 1 ) ans = "Impossible";

	cout << ans << endl;
}
