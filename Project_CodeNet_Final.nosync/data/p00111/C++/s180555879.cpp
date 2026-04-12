#include <cstdio>
#include <string>
#include <map>
#include <utility>

using namespace std;

static const pair<string,char> t2[ 32 ] = {
  make_pair ( "101"     , ' ' ),
  make_pair ( "000000"  , '\'' ),
  make_pair ( "000011"  , ',' ),
  make_pair ( "10010001", '-' ),
  make_pair ( "010001"  , '.' ),
  make_pair ( "000001"  , '?' ),
  make_pair ( "100101"  , 'A' ),
  make_pair ( "10011010", 'B' ),
  make_pair ( "0101"    , 'C' ),
  make_pair ( "0001"    , 'D' ),
  make_pair ( "110"     , 'E' ),
  make_pair ( "01001"   , 'F' ),
  make_pair ( "10011011", 'G' ),
  make_pair ( "010000"  , 'H' ),
  make_pair ( "0111"    , 'I' ),
  make_pair ( "10011000", 'J' ),
  make_pair ( "0110"    , 'K' ),
  make_pair ( "00100"   , 'L' ),
  make_pair ( "10011001", 'M' ),
  make_pair ( "10011110", 'N' ),
  make_pair ( "00101"   , 'O' ),
  make_pair ( "111"     , 'P' ),
  make_pair ( "10011111", 'Q' ),
  make_pair ( "1000"    , 'R' ),
  make_pair ( "00110"   , 'S' ),
  make_pair ( "00111"   , 'T' ),
  make_pair ( "10011100", 'U' ),
  make_pair ( "10011101", 'V' ),
  make_pair ( "000010"  , 'W' ),
  make_pair ( "10010010", 'X' ),
  make_pair ( "10010011", 'Y' ),
  make_pair ( "10010000", 'Z' ) };

int strcmp2 (
  const char * s,
  const char * d
  )
{
  const char * it;

  for ( it = s; *it != '\0'; ++it )
  {
    if ( *it != *d ) break ;
    ++d;
  }

  return ( *it == '\0'
         ? it - s : 0 );
}

/** Application main entry point. */
int
main (
  int     argc,
  char  * argv[ ]
  )
{
  map<char,string> t1;
  string sb;
  int i;

  t1[ 'A' ] = "00000";
  t1[ 'B' ] = "00001";
  t1[ 'C' ] = "00010";
  t1[ 'D' ] = "00011";
  t1[ 'E' ] = "00100";
  t1[ 'F' ] = "00101";
  t1[ 'G' ] = "00110";
  t1[ 'H' ] = "00111";
  t1[ 'I' ] = "01000";
  t1[ 'J' ] = "01001";
  t1[ 'K' ] = "01010";
  t1[ 'L' ] = "01011";
  t1[ 'M' ] = "01100";
  t1[ 'N' ] = "01101";
  t1[ 'O' ] = "01110";
  t1[ 'P' ] = "01111";
  t1[ 'Q' ] = "10000";
  t1[ 'R' ] = "10001";
  t1[ 'S' ] = "10010";
  t1[ 'T' ] = "10011";
  t1[ 'U' ] = "10100";
  t1[ 'V' ] = "10101";
  t1[ 'W' ] = "10110";
  t1[ 'X' ] = "10111";
  t1[ 'Y' ] = "11000";
  t1[ 'Z' ] = "11001";
  t1[ ' ' ] = "11010";
  t1[ '.' ] = "11011";
  t1[ ',' ] = "11100";
  t1[ '-' ] = "11101";
  t1[ '\'' ]= "11110";
  t1[ '?' ] = "11111";

  for ( ; ; )
  {
    sb = "";

    for ( ; ; )
    {
      const char ch = getchar ( );

      if ( ch == EOF ) return ( 0 );
      if ( ch == '\n' ) break ;
      sb += t1[ ch ];
    }

    while ( !sb.empty ( ) )
    {
      for ( i = 0; i < 32; ++i )
      {
        const int f = strcmp2 ( t2[ i ].first.c_str ( ), sb.c_str ( ) );

        if ( f )
        {
          putchar ( t2[ i ].second );
          sb.erase ( 0, f );
          break ;
        }
      }

      if ( i == 32 ) break ;
    }

    puts ( "" );
  }

  return ( 1 );
}