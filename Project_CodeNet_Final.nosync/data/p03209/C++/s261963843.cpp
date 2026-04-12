#include <algorithm>
#include <array>
#include <bitset>
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
  std::cerr << std::fixed << std::setprecision(6);

  int N;

  long long X;

  std::cin >> N >> X;

  long long x[55], p[55], b[55];

  x[0] = (p[0] = 1) + (b[0] = 0);

  for (int i = 1; i < 55; i ++)
    x[i] = (p[i] = p[i - 1] * 2 + 1) + (b[i] = b[i - 1] * 2 + 2);

  int L = N;

  long long P = 0;

  for ( ; X; L --)
    if (X == x[L]) {
      P += p[L];

      break;
    }
    else if (X <= x[L - 1] + 1) {
      X --;
    }
    else {
      X -= x[L - 1] + 1 + 1;
      P += p[L - 1] + 1;
    }

  std::cout << P << std::endl;

  return 0;
}
