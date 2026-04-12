#include <iostream>
using namespace std;

signed main() {
  int X, Y, Z; cin >> X >> Y >> Z;
  int sum = X-Z;
  cout << sum / (Y+Z) << endl;
}
