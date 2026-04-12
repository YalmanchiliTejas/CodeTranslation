#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int H, W; cin >> H >> W;
	vector<string> Grid(H);
	for( string &k : Grid ) cin >> k;
	
	string none;
	for( int i = 0 ; i < W ; i++ ){
		none += '.';
	}
	
	for( int i = 0 ; i < H ; i++ ){
		if( Grid[i] == none ){
			Grid.erase(Grid.begin() + i);
			H--;   i--;
		}
	}
	
	for( int i = 0 ; i < W ; i++ ){
		for( int j = 0 ; j < H ; j++ ){
			if( Grid[j][i] == '#' ) goto out;
		}
		for( int k = 0 ; k < H ; k++ ){
			Grid[k].erase(i,1);
			if( k == H - 1 ){
				W--; i--;
			}
		}
		out:;
	}
	
	for( string &k : Grid ) cout << k << endl;
	
}