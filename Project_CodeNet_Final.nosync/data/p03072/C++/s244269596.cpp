#include <iostream>
using namespace std;

int main() {
  int n;
  while ( cin >> n ) {
    int answer = 1, x, mx;
    cin >> x;
    mx = x;
    for ( int i = 1; i < n; ++i ) {
      cin >> x;
      if ( x >= mx ) { mx = x; answer++; }
    }
    cout << answer << endl;
    
  }
  return 0;
}