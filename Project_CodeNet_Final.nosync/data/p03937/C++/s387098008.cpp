#include <bits/stdc++.h>

using namespace std;
const int N = 8;
int _w;

int n, m, a[N][N], k, b[N][N];

bool check( int s ) {
	memset(b, 0, sizeof b);
	b[0][0] = 1;
	int x = 0, y = 0;
	for( int i = 0; i < k; ++i ) {
		int d = (s>>i)&1;
		d ? ++x : ++y;
		if( x == n || y == m ) return false;
		b[x][y] = 1;
	}
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < m; ++j )
			if( a[i][j] != b[i][j] )
				return false;
	return true;
}

int main() {
	cin >> n >> m, k = n+m-2;
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < m; ++j ) {
			char ch;
			_w = scanf( " %c", &ch );
			a[i][j] = ch == '#';
		}
	for( int i = 0; i < (1<<k); ++i )
		if( check(i) )
			return puts("Possible"), 0;
	return puts("Impossible"), 0;
}
