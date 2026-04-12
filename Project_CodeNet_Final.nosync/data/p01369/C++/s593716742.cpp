#include <iostream>
#include <string>
using namespace std;

int main() {

  int d[26] = { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 };

  while( true ) {

    string in;
    cin >> in;
    if ( in == "#" ) break;

    long long int h = d[ in[0] - 'a' ];
    long long int ans = 0;

    for ( long long int i = 0; i < in.size(); i++ ) {

      long long int k = d[ in[i] - 'a' ];
      if ( h != k ) ans++;
      h = k;

    }
    cout << ans << endl;

  }

  return 0;

}