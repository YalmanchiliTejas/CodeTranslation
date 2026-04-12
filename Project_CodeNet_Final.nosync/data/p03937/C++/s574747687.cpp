//by tzupengwang™
#include<algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

int n , m ;
char s[ 50 ][ 50 ] ;

void init() {
  scanf( "%d%d" , &n , &m ) ;
  for ( int i = 0 ; i < n ; i ++ ) scanf( "%s" , s[ i ] ) ;
}
int cnt[ 25 ] ;

void process() {
  for ( int i = 0 ; i < n ; i ++ ) {
    for ( int j = 0 ; j < m ; j ++ ) {
      if ( s[ i ][ j ] == '#' ) {
        cnt[ i + j ] += 1 ;
        if ( i + j != 0 ) {
          if ( ( j == 0 || s[ i ][ j - 1 ] != '#' ) && ( i == 0 || s[ i - 1 ][ j ] != '#' ) ) {
            puts( "Impossible" ) ;
            return ;
          }
        }
      }
    }
  }
  for ( int i = 0 ; i <= n + m - 2 ; i ++ ) {
    if ( cnt[ i ] != 1 ) {
      puts( "Impossible" ) ;
      return ;
    }
  }
  puts( "Possible" ) ;
}

int main() {
  init() ;
  process() ;
  return 0 ;
}
