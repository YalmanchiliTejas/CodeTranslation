
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <cmath>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <numeric>  // std::accumulate(m.begin(), m.end(), 0LL);
#include <functional>
#include <cassert>
#include <cctype>  // std::islower(), std::isupper(), std::tolower, std::toupper
#include <iomanip> // std::setprecision(X)
#include <limits>  //std::numeric_limits<int>::max(), min()

typedef long long ll;

int main (void) {
  int X, Y, Z; std::cin >> X >> Y >> Z;

  int ans = 1;
  X -= Z;
  std::cout << ans + X/(Y+Z) - 1 << std::endl;
  return 0;
}
