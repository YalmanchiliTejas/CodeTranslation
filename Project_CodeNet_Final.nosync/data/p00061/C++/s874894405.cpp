#include <cstdio>
#include <map>

#define N 30

using namespace std;

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  int rank[ N + 1 ] = { 0 };
  map < int, int >  stk;
  int n;
  int i;

  for ( ; ; )
  {
    int r;

    scanf ( "%d,%d", &n, &r );
    if ( !( n | r ) ) break;

    stk[ n ] = r;
    ++rank[ r ];
  }

  n = 0;
  for ( i = N; i >= 0; --i )
  {
    if ( rank[ i ] )
    {
      rank[ i ] = ++n;
    }
  }

  while ( scanf ( "%d", &n ) == 1 )
  {
    printf ( "%d\n", rank[ stk[ n ] ] );
  }

  return ( 0 );
}