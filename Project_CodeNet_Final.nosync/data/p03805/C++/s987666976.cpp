#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

void ntoarray( int a[], int n ) {
	int i = 0;
	while( n > 0 ) {
		a[ i ] = n % 10; n = n / 10;
		i += 1;
	}
	return;
}

bool chk_permu( int n, int i ) {
	const int amax = 12;
	int na[ amax ] = { 0 };
	int ia[ amax ] = { 0 };

	ntoarray( na, n );
	std::sort( na, na + amax );
	ntoarray( ia, i );
	std::sort( ia, ia + amax );

	bool issame = true;
	for( int i = 0; i < amax; i++ ) {
		if( na[ i ] !=  ia[ i ] ) {
			issame = false;
			break;
		}
	}

	return issame;
}

int next_permu( int n, int nmax ) {
	int p = 0;
	for( int i = n + 1; i < nmax; i++ ) {
		bool ispermu = chk_permu( n, i );
		if( ispermu ) {
			p = i;
			break;
		}
	}
	return p;
}

bool isallconnected( int np, int n, int m, int a[], int b[] ) {
	std::vector<int> nv;
	int t = np;
	while( t > 0 ) {
		nv.insert( nv.begin(), t % 10 );
		t = t / 10;
	}

	int edges = 0;
	for( int i = 0; i < nv.size() - 1; i++ ) {
		for( int j = 0; j < m; j++ ) {
			if( ( nv[ i ] == a[ j ] and nv[ i + 1 ] == b[ j ] ) or
					( nv[ i ] == b[ j ] and nv[ i + 1 ] == a[ j ] ) ) {
				edges += 1;
			}
		}
	}

	return ( edges == n - 1 ? true : false );
}

int main( void )
{
	int n, m;
	std::cin >> n >> m;

	const int mmax = 28;
	int a[ mmax ], b[ mmax ];
	for( int i = 0; i < m; i++ ) {
		std::cin >> a[ i ] >> b[ i ];
	}

	int np = 0;
	for( int i = 1; i <= n; i++ ) {
		np = np * 10 + i;
	}

	int nmax = std::pow( 10, n - 1 ) * 2;
	int cnt = 0;
	while( np > 0 ) {
		bool isall = isallconnected( np, n, m, a, b );
		if( isall ) {
			cnt += 1;
		}

		np = next_permu( np, nmax );
	}

	std::cout << cnt << std::endl;
	return 0;
}

