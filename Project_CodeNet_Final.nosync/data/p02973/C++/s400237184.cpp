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

using namespace std;

int main()
{
  uint64_t N;
  cin >> N;

  vector<uint64_t> A(N);
  N_TIMES(n, N) { cin >> A[n]; }
  reverse(A.begin(), A.end());

  const uint64_t INF = static_cast<uint64_t>(-1);
  vector<uint64_t> B(N, INF);
  N_TIMES(i, N) {
    auto itr = upper_bound(B.begin(), B.end(), A[i]);
    uint64_t j = distance(B.begin(), itr);
    B[j] = A[i];
  }

  uint64_t C = 0;
  N_TIMES(i, N) {
    if (B[i] == INF) { break; }
    ++C;
  }
  cout << C << endl;

  return 0;
}