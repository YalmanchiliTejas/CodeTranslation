#include<iostream>
#include<iomanip>
#include<utility>
#include<cstring>

typedef std::pair<int, int> P;

int n;
int sq[15][15];

int main()
{
	while( std::cin >> n, n )
	{
		memset( sq, 0, sizeof( sq ) );

		P p = P( n / 2, n / 2 + 1 );

		int cnt = 1;
		while( true )
		{
			if( cnt == n * n + 1 )
				break;

			int x = p.first, y = p.second;

			sq[y][x] = cnt;

			int nx = ( x + 1 ) % n, ny = ( y + 1 ) % n;
			if( sq[ny][nx] )
				p = P( ( nx - 1 + n ) % n, ( ny + 1 ) % n );
			else
				p = P( nx, ny );

			++cnt;
		}

		for( int i = 0; i != n; ++i )
		{
			for( int j = 0; j != n; ++j )
				std::cout << std::setw( 4 ) << std::right << sq[i][j];

			std::cout << std::endl;
		}
	}

	return 0;
}