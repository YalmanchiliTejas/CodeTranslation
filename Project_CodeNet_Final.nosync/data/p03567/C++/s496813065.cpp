#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main (){
	char ch [6];
	scanf ( "%s" , ch ) ;
	int len = strlen ( ch ) ;
	for ( int i = 1 ; i < len ; ++ i )
		if ( ch [i-1] == 'A' && ch [i] == 'C' ) {
			printf ( "Yes" );
			return 0 ;
		}
	printf ( "No" );
	return 0 ;
}