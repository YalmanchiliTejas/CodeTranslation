#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int num = X / (Y + Z);
  if (X % (Y + Z) < Z)
    num--;
  cout << num << endl;
}
