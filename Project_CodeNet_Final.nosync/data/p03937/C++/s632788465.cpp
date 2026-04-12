#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int h, w; cin >> h >> w;
	int a[h+1][w+1];
	
	// init
	for( int i = 0; i <= h; ++i ){
		for( int j = 0; j <= w; ++j ){
			a[i][j] = '.';
		}
	}
	int cnt = 0;
	for( int i = 0; i < h; ++i ){
		for( int j = 0; j < w; ++j ){
			char c; cin >> c;
			a[i][j] = c;
			if( c == '#' ) ++cnt;
		}
	}
	
	bool flag = true;
	if( a[0][0] == '.' || a[h-1][w-1] == '.' || cnt != w+h-1 ){
		flag = false;
	} else {
		int x = 0, y = 0;
		for( int i = 0; i < w+h-2; ++i ){
			if( a[x+1][y] == a[x][y+1] ){
				flag = false;
				break;
			} else {
				if( a[x+1][y] == '#' ){
					++x;
				} else {
					++y;
				}
			}
		}
	}
	
	cout << ( flag ? "P" : "Imp" ) << "ossible" << endl;
	return 0;
}