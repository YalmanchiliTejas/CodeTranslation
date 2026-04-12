#include <bits/stdc++.h>
using namespace std ;
typedef int Read ; // Here to change the type of numbers
inline Read Readin() {
	Read K = 0 , F = 1 ; char C = ' ' ;
	while( C < '0' or C > '9' ) F = C == '-' ? -1 : 1 , C = getchar() ;
	while( C <= '9' and C >= '0' ) K = ( K << 1 ) + ( K << 3 ) + C - '0' , C = getchar() ;
	return F * K ;
}
inline Read Min( Read A , Read B ) { return A < B ? A : B ; }
inline Read Max( Read A , Read B ) { return A > B ? A : B ; }
inline Read Abs( Read A ) { return A < 0 ? -A : A ; }

int main() {
	
	int N ;
	N = Readin() ;
	if( N - 7 == 0 or N - 5 == 0 or N - 3 == 0 ) printf( "YES\n" ) ;
	else printf( "NO\n" ) ;
	return 0 ; 
	
}