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

  long long N, K;

  std::cin >> N >> K;

  long long C = 0;

  if (K == 0) {
    C = N * N;
  }
  else {
    for (long long b = K + 1; b <= N; b ++) {
      long long c = N / b, u = c * b;

      C += (b - K) * c;

      if (u + 1 <= N) {
        int l = (u + 1) % b, u = N % b;

        l = std::max<long long>(l, K);
        u = std::min<long long>(u, b - 1);

        C += std::max(u - l + 1, 0);
      }
    }
  }

  std::cout << C << std::endl;
  
  return 0;
}
