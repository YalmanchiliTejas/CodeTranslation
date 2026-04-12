#include<stdio.h>



int main()
{
	int a ,b ;


	while( 1 )
	{
		scanf( "%d %d" ,&a ,&b ) ;


		if( ( a | b ) == 0 )
		{
			return 0 ;
		}


		char c = 'A' ;

		int ans = a + b ;


		for( int i = 1 ; i <= 4 ; ++i )
		{
			scanf( "%d %d" ,&a ,&b ) ;



			if( ans < a + b )
			{
				ans = a + b ;

				c = i + 'A' ;
			}
		}



		printf( "%c %d\n" ,c ,ans ) ;
	}
}