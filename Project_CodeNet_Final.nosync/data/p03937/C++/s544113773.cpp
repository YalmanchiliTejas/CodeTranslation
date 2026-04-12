#include <bits/stdc++.h>
using namespace std;

string s[10];
int main(){
	int H,W;
	cin >> H >> W;
	int cnt = 0;
	for(int i = 0 ; i < H ; i++){
		cin >> s[i];
		cnt += count(s[i].begin(),s[i].end(),'#');
	}
	int ans = 0;
	if( cnt != H + W - 1 ){
		cout << "Impossible" << endl;
		return 0;
	}
	
	for(int i = 0 ; i < (1<<(H + W - 2)) ; i++){
		int x = 0, y = 0;
		int res = 1;
		for(int j = 0 ; j < H + W - 2 ; j++){
			if( i >> j & 1 ){
				x += 1;
			}else{
				y += 1;
			}
			if( y >= H or x >= W or s[y][x] != '#'){
				res = 0;
			}
		}
		if( res ) ans = 1;
	}
	if( !ans ){
		cout << "Impossible" << endl;
	}else{
		cout << "Possible" << endl;
	}
	
}