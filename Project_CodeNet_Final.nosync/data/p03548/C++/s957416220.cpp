#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;

  X -= Z;
  cout << X / (Y + Z) << endl;

  return 0;
}
