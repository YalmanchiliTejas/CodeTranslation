#include <iostream>
using namespace std;

int main() {

  long long int n;

  while( true ) {

    cin >> n;

    if ( n == 0 ) break;

    int map[99][99] = {0};

    long long int x = n / 2;
    long long int y = n / 2 + 1;

    for ( long long int i = 1; i <= n * n; i++ ) {

      if ( map[x][y] == 0 ) {
	map[x][y] = i;
	x = ( x + 1 ) % n;
	y = ( y + 1 ) % n;
      }else {
	x = ( x - 1 + n ) % n;
	y = ( y + 1 ) % n;
	i--;
      }

    }

    for ( long long int i = 0; i < n; i++ ) {
      for ( long long int j = 0; j < n; j++ ) {

	if ( map[j][i] < 10 ) {
	  cout << "   " << map[j][i];
	}else if ( map[j][i] < 100 ) {
	  cout << "  " << map[j][i];
	}else {
	  cout << " " << map[j][i];
	}

      }
      cout << endl;
    }

  }

  return 0;

}