#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 4000000000000000000LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);

  int X, Y, Z;

  std::cin >> X >> Y >> Z;

  int c = 0;

  for ( ; ; c ++) {
    long long x = Y * c + (c > 0 ? (c + 1) * Z : 0);

    if (x > X) {
      c --;
      
      break;
    }
  }

  std::cout << c << std::endl;

  return 0;
}
