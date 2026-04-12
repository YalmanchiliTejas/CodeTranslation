
#include <bits/stdc++.h>
using namespace std;

char S[ 60 ][ 60 ];
int iCnt[ 30 ];
int iMin[ 30 ];

int main()
{
int i;
int j;
int n;
int iMax;
char C;

	cin >> n;

	for( i = 0; i < n; i++ ) cin >> S[ i ];

	j = 0;
	while( ( C = S[ 0 ][ j ] ) != '\0' )
	{
		iMin[ C - 'a' ]++;
		j++;
	}

	for( i = 1; i < n; i++ )
	{
		memset( iCnt, 0, 26 * 4 );

		j = 0;
		while( ( C = S[ i ][ j ] ) != '\0' )
		{
			iCnt[ C - 'a' ]++;
			j++;
		}

		for( j = 0; j < 26; j++ )
			iMin[ j ] = min( iMin[ j ], iCnt[ j ] );
	}

	for( i = 0; i < 26; i++ )
		cout << string( iMin[ i ], 'a' + i );

	cout << endl;

	return 0;
}




