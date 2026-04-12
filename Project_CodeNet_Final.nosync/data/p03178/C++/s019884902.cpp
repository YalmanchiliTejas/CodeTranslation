#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

constexpr unsigned Mod = 1000000007;

constexpr unsigned Add(unsigned a, unsigned b) { return (a + b) % Mod; }

int main() {
  static char K[10001];
  int D;
  scanf("%s%d", K, &D);
  auto N = (int) strlen(K);
  static unsigned F[10001][100][2];
  F[0][0][1] = 1;
  for (auto i = 1; i <= N; ++i) {
    for (auto j = 0; j < D; ++j) {
      for (auto k = 0; k < 10; ++k) {
        auto l = (j + k) % D;
        F[i][l][0] = Add(F[i][l][0], F[i - 1][j][0]);
        if (k < K[i - 1] - '0')
          F[i][l][0] = Add(F[i][l][0], F[i - 1][j][1]);
        if (k == K[i - 1] - '0')
          F[i][l][1] = Add(F[i][l][1], F[i - 1][j][1]);
      }
    }
  }
  printf("%u\n", Add(F[N][0][0] + F[N][0][1], Mod - 1));
  return 0;
}
