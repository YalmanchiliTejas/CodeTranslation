#include <iostream>
#include <iomanip>
using namespace std;

void move( int& x, int& y, int n, int flag ){
	if ( !flag ){
		x += 1;
		y += 1;
	}else{
		x -= 1;
		y += 1;
	}
	if ( x < 0 ) x = n - 1;
	else if ( x >= n ) x = 0;
	if ( y < 0 ) y = n - 1;
	else if ( y >= n ) y = 0;
}

int main(){
	int n;
	while ( cin >> n && n ){
		int* table = new int[ ( n * n ) ]();
		int x = n / 2, y = n / 2 + 1;
		for ( int i = 0; i < n * n; ++i ){
			if ( table[ y * n + x ] ){
				move( x, y, n, 1 );
			}
			table[ y * n + x ] = i + 1;
			move( x, y, n, 0 );
		}

		for ( int j = 0; j < n; ++j ){
			for ( int i = 0; i < n; ++i ){
				cout << setw( 4 );
				cout << table[ j * n + i ];
			}
			cout << endl;
		}

		delete[] table;
	}
	return 0;
}