#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std ;

int main()
{
	short n[ 101 ] ;
	for( int i = 0 ; i < 12 ; i++ )
		cin >> n[ i ] ;
	sort( n ,n + 12 ) ;
	short a = n[ 0 ] ,b = n[ 4 ] ,c = n[ 8 ] ;
	short ans = 0 ;
	for( int i = 0 ; i < 4 ; i++ )
	{
		if( a == n[ i ] )
			ans++ ;
		if( b == n[ i + 4 ] )
			ans++ ;
		if( c == n[ i + 8 ] )
			ans++ ;
	}
	if( ans == 12 )
		puts( "yes" ) ;
	else
		puts( "no" ) ;
	return 0 ;
}