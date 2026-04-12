#include <iostream>
using namespace std;

int main() {
  int X, Y, Z, a=0;
  cin >> X >> Y >> Z;
  while (true) {
    if (X<Y+Z+Z) {
      break;
    } else {
      a+=1;
      X-=Y+Z;
    }
  }
  cout << a << endl;
  return 0;
}
