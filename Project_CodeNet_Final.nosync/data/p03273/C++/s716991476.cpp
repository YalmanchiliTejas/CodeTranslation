#include <bits/stdc++.h>
using namespace std;

#define H 100
#define W 100

int h, w;
char a[H][W];

int main() {
	cin >> h >> w;

	for( int i = 0; i < h; i++ ) {
		for( int j = 0; j < w; j++ ) {
			cin >> a[i][j];
		}
	}

	int flag1;
	int flag;
	do {
		flag1 = 0;
		for( int i = 0; i < h; i++ ) {
			int flag = 0;
			for( int j = 0; j < w; j++ ) {
				if( a[i][j] == '#' ) {
					flag = 1;
				}
			}
			if( flag == 0 ) {
				for( ; i < h; i++ ) {
					for( int j = 0; j < w; j++ ) {
						a[i][j] = a[i + 1][j];
					}
				}
				h--;
				flag1 = 1;
			}
		}
	} while( flag1 == 1 );

	do {
		flag1 = 0;
		for( int i = 0; i < w; i++ ) {
			int flag = 0;
			for( int j = 0; j < h; j++ ) {
				if( a[j][i] == '#' ) {
					flag = 1;
				}
			}
			if( flag == 0 ) {
				for( ; i < w; i++ ) {
					for( int j = 0; j < h; j++ ) {
						a[j][i] = a[j][i + 1];
					}
				}
				w--;
				flag1 = 1;
			}
		}
	} while( flag1 == 1 );

	for( int i = 0; i < h; i++ ) {
		for( int j = 0; j < w; j++ ) {
			cout << a[i][j];
		}
		cout << endl;
	}

	return 0;
}
