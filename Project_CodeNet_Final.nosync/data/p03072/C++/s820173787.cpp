#include <stdio.h>
int main( void )
{
  	int N;
	scanf("%d", &N ) ;
    int M=0,V=0;
    for( int i = 0 ; i < N ; i++ ) {
		int H;
		scanf("%d", &H ) ;
      	if( H >= M ) {
          	V++;
          	M = H ;
        }
    }
  	printf("%d", V ) ;
  	return 0 ;
}