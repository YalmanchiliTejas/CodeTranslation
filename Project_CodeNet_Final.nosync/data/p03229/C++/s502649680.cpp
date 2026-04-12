#include <iostream>
#include <sstream>
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
  N_TIMES(n, N) {
    cin >> A[n];
  }
  sort(A.begin(), A.end());

  uint64_t M = N / 2, S = 0;
  if (N % 2 == 0) {
    for (uint64_t i = M; i < N; ++i) {
      S += A[i] * 2;
    }
    S -= A[M];
    S += A[M - 1];
    for (uint64_t i = 0; i < M; ++i) {
      S -= A[i] * 2;
    }
  } else { // N % 2 == 1
    uint64_t P = 0;
    for (uint64_t i = M; i < N; ++i) {
      P += A[i] * 2;
    }
    P -= A[M] + A[M + 1];
    for (uint64_t i = 0; i < M; ++i) {
      P -= A[i] * 2;
    }

    uint64_t Q = 0;
    for (uint64_t i = M + 1; i < N; ++i) {
      Q += A[i] * 2;
    }
    Q += A[M - 1] + A[M];
    for (uint64_t i = 0; i < M + 1; ++i) {
      Q -= A[i] * 2;
    }

    S = max(P, Q);
  }
  cout << S << endl;
  
  return 0;
}