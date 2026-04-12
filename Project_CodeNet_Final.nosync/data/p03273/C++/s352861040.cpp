
#include <bits/stdc++.h>
using namespace std;

char A[ 110 ][ 110 ];
bool h[ 110 ];
bool w[ 110 ];

int main()
{
int i;
int j;
int H;
int W;

	ios::sync_with_stdio( false );
	cin.tie( 0 );

	cin >> H;
	cin >> W;

	for( i = 0; i < H; i++ )
	{
		cin >> A[ i ];
		for( j = 0; j < W; j++ )
		{
			if( A[ i ][ j ] == '#' )
			{
				h[ i ] = true;
				w[ j ] = true;
			}
		}
	}

	for( i = 0; i < H; i++ )
	{
		if( ! h[ i ] ) continue;

		for( j = 0; j < W; j++ )
		{
			if( w[ j ] ) cout << A[ i ][ j ];
		}

		cout << endl;
	}

	return 0;
}




