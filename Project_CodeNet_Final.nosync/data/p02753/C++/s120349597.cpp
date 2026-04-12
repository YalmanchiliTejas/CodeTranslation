
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main( int argc, char *argv[] )
{
  char bus[10];
  int yes=0;

  scanf( "%s", bus );

  if( bus[0] != bus[1] ) yes = 1;
  if( bus[1] != bus[2] ) yes = 1;
  if( yes ) printf( "Yes\n" );
  else printf( "No\n" );

/*
  long long n;
  long long a,b;
  long long aa;
  long long l;

  scanf( "%ld %ld %ld", &n, &a, &b );
  l = abs(a-b);
  if( l%2 ){
    if( a > b ){
      aa = b; b = a; a = aa;
    }
    if( n-a > b-1 ) printf( "%ld\n", b-1 );
    else printf( "%ld\n", n-a );
  }
  else{
    printf( "%ld\n", l/2 );
  }
*/
}
