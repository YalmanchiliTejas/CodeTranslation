#include<iostream>

using namespace std  ;

int st[ 100002 ] = { 0 } ;

int main()
{
	int j ;
	int n ;
	int cnt = 0 ;
	cin >> n ;
	while( n != 0 )
	{
		for( int i = 0 ; i < n ; i += 2 )
		{
			cin >> st[ i ] ;
			if( n - i != 1 )
			{
				cin >> st[ i + 1 ] ;
				if( st[ i ] != st[ i + 1 ] )
				{
					j = i ;
					while( st[ j ] != st[ j + 1 ] )
					{
						st[ j ] = st[ j + 1 ] ;
						j-- ;
						if( j < 0 )
						{
							break ;
						}
					}
				}
			}
		}
		for( int i = 0 ; i < n ; i++ )
		{
			if( st[ i ] == 0 )
			{
				cnt++ ;
			}
		}
		cout << cnt << endl ;
		cnt = 0 ;
		cin >> n ;
	}
	return 0 ;
}