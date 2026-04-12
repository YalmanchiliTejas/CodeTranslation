#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>

using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int ans = 0;
  X -= Z;
  while (X >= Z + Y) {
    X -= Z + Y;
    ans++;
  }

  cout << ans << endl;

  return 0;
}
