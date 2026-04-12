#include <cstdio>
#include <algorithm>

#define N 10000

using namespace std;

/** Application main entry point. */
int
main (
  int     argc,
  char  * argv[ ]
  )
{
  int i, j;

  for ( ; ; )
  {
    int d[ N * 2 ];
    int n, m;
    int res;

    scanf ( "%d%d", &n, &m );
    if ( !( n | m ) ) break ;
    m += n;

    for ( i = 0; i < n; ++i )
    {
      scanf ( "%d", &d[ i ] );
    }
    for ( i = n; i < m; ++i )
    {
      scanf ( "%d", &d[ i ] );
    }
    inplace_merge ( d, d + n, d + m );

    res = d[ 0 ];
    for ( i = 1; i < m; ++i )
    {
      res = max( res, d[ i ] - d[ i - 1 ] );
    }
    printf ( "%d\n", res );
  }

  return ( 0 );
}