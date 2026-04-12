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

int main() {
  int N;
  cin >> N;
  static long long S[3001], F[3000];
  copy_n(istream_iterator<int>(cin), N, F);
  partial_sum(F, F + N, S + 1);
  for (auto i = 2; i <= N; ++i)
    for (auto j = 0; j <= N - i; ++j)
      F[j] = S[j + i] - S[j] - min(F[j], F[j + 1]);
  cout << F[0] * 2 - S[N] << endl;
  return 0;
}
