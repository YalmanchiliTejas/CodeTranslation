#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int ans = (x - z) / (y + z);
  cout << ans << endl;
}
