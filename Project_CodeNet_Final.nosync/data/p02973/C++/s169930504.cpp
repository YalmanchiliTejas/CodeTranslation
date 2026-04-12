#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

uint64_t length_of_longest_decrease_subsequence(const std::vector<uint64_t> &A)
{
  const int64_t INF = static_cast<int64_t>(-1e+8);

  std::vector<int64_t> dp(A.size(), INF);

  for (uint64_t i = 0; i < A.size(); ++i) {
    auto itr = std::lower_bound(dp.begin(), dp.end(), A[i], std::greater_equal<int64_t>());
    uint64_t j = std::distance(dp.begin(), itr);
    dp[j] = A[i];
  }

  uint64_t counter = 0;
  for (; (counter < A.size()) && (dp[counter] != INF); ++counter);
  return counter;
}

using namespace std;

int main()
{
  uint64_t N;
  cin >> N;

  vector<uint64_t> A(N);
  N_TIMES(n, N) { cin >> A[n]; }

  cout << length_of_longest_decrease_subsequence(A) << endl;

  return 0;
}