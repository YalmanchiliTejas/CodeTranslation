#include <cstdio>
#include <algorithm>

using namespace std;

/** Application main entry point. */
int main (
  int     argc,
  char  * argv[ ]
  )
{
  for ( ; ; )
  {
    int d[ 6 ] = { 1, 2, 3, 5, 4, 6 };
    int res = 1;
    int n;

    scanf ( " %d", &n );
    if ( !( n ) ) break ;

    while ( n-- )
    {
      char cmd[ 8 ];

      scanf ( " %s", cmd );
      if ( *cmd == 'N' )
      {
        swap ( d[ 3 ], d[ 0 ] );
        swap ( d[ 0 ], d[ 1 ] );
        swap ( d[ 1 ], d[ 5 ] );
      }
      else if ( *cmd == 'E' )
      {
        swap ( d[ 2 ], d[ 0 ] );
        swap ( d[ 0 ], d[ 4 ] );
        swap ( d[ 4 ], d[ 5 ] );
      }
      else if ( *cmd == 'W' )
      {
        swap ( d[ 4 ], d[ 0 ] );
        swap ( d[ 0 ], d[ 2 ] );
        swap ( d[ 2 ], d[ 5 ] );
      }
      else if ( *cmd == 'S' )
      {
        swap ( d[ 1 ], d[ 0 ] );
        swap ( d[ 0 ], d[ 3 ] );
        swap ( d[ 3 ], d[ 5 ] );
      }
      else if ( *cmd == 'R' )
      {
        rotate ( d + 1, d + 2, d + 5 );
      }
      else if ( *cmd == 'L' )
      {
        rotate ( d + 1, d + 4, d + 5 );
      }

      res += *d;
    }
    
    printf ( "%d\n", res );
  }

  return ( 0 );
}