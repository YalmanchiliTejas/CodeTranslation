#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main( void )
{
	int n;
	while ( cin >> n && n )
	{
		vector < vector<int> > ms( n, vector<int>(n,0) );
		int x = n/2;
		int y = n/2+1;
		int cnt = 1;

		while ( cnt <= n * n )
		{
			x = x<0?n-1:x;
			y = y<0?n-1:y;
			x = x>=n?0:x;
			y = y>=n?0:y;

			if ( ms[y][x] != 0 )
			{
				x--;
				y++;
				continue;
			}

			ms[y][x] = cnt;

			x++;
			y++;
			cnt++;
		}

		for ( int i = 0; i < n; i++ )
		{
			for ( int j = 0; j < n; j++ )
				cout << setw( 4 ) << ms[i][j];
			cout << endl;
		}

	}
	return 0;
}