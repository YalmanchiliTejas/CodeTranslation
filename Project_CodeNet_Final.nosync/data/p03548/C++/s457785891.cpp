#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int X, Y, Z;

int main() {
  cin >> X >> Y >> Z;

  int count = 1;
  X -= Y + 2 * Z;
  count += X / (Y + Z);

  cout << count << endl;

  return 0;
}
