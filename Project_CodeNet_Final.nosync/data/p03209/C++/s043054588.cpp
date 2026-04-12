#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

LL N, X;
vector<LL> L, P;

LL dfs(LL i, LL n) {
  if (n <= 0) return  0LL;
  if (L[i] <= n) {
    return P[i];
  }

  --n;  // B

  LL cnt = dfs(i-1, n);
  n -= L[i-1];
  if (n <= 0) return cnt;

  --n; // P
  ++cnt;

  cnt += dfs(i-1, n);
  n -= L[i-1];
  if (n <= 0) return cnt;

  assert(false);
  // B
}

int main() {
  cin >> N >> X;
  L.resize(N + 1), P.resize(N + 1);
  L[0] = 1, P[0] = 1;

  for (int i = 0; i < N; ++i) {
    L[i + 1] = 2LL * L[i] + 3LL;
    P[i + 1] = 2LL * P[i] + 1LL;
  }

  cout << dfs(N, X) << endl;
}
