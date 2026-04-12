#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  while( 1 ) {
    int ss[ 5 ];
    int a, b;
    int maxidx = 0;
    cin >> a >> b;
    if( !a && !b ) {
      return EXIT_SUCCESS;
    }
    ss[ 0 ] = a + b;
    for( int i = 1; i < 5; i++ ) {
      cin >> a >> b;
      ss[ i ] = a + b;
      if( ss[ i ] > ss[ maxidx ] ) {
        maxidx = i;
      }
    }
    cout << ( char )( 'A' + maxidx ) << " " << ss[ maxidx ] << endl;
  }
};