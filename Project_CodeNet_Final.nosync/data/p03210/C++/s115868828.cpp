#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

#define EPS (1e-7)

int main() {
  ll X;
  cin >> X;
  string ans = "NO";
  if (X == 7 || X == 5 || X == 3) {
    ans = "YES";
  }

  cout << ans << endl;
  return 0;
}
