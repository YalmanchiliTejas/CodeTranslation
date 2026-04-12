#include <iostream>
using namespace std;
int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int count = 0;
  X -= Z;
  while (1) {
    if (X < (Y+Z))
      break;
    else {
      count++;
      X -= Y+Z;
    }
  }
  cout << count << endl;
  return 0;
}
