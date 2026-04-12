#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int X,Y,Z; cin >> X >> Y >> Z;
  X -= 2*Z;
  int cnt = 0;
  while(1) {
    if ( X - Y >= 0 ){
    X -=Y;
    cnt++;
    X -= Z;
    } else {
      break;
    }
  }
  cout << cnt << endl;
  return 0;
}
