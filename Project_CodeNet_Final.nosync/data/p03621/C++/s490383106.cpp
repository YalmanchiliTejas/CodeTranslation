#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

char A[10050], B[10050];
Int fact[50050], inv[50050], finv[50050];
const Int MO = 998244353;

Int comb(int n, int r) {
  return fact[n] * finv[r] % MO * finv[n - r] % MO;
}

// Int dp[512][512];

Int U[10050], V[10050];

int main() {
  scanf("%s%s", A, B);
  const int N = strlen(A);

  inv[1] = 1;
  for (int i = 2; i < 50050; ++i) {
    inv[i] = MO - MO / i * inv[MO % i] % MO;
  }
  fact[0] = finv[0] = 1;
  for (int i = 1; i < 50050; ++i) {
    fact[i] = fact[i - 1] * i % MO;
    finv[i] = finv[i - 1] * inv[i] % MO;
  }

  int C = 0, E = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] == '1' && B[i] == '1') {
      ++C;
    } else if (A[i] == '1') {
      ++E;
    }
  }

  Int res = 0;
  U[0] = 1;
  for (int c = 0; c <= C; ++c) {
    memset(V, 0, sizeof(V));
    for (int e = 1; e <= E; ++e) {
      (U[e] += U[e - 1] * (E - (e - 1)) % MO) %= MO;
    }

    (res += U[E] * fact[E] % MO * comb(C, c) % MO * fact[c] % MO * fact[C - c] % MO * fact[C - c] % MO * comb(C + E, C - c) % MO) %= MO;

    for (int e = 0; e <= E; ++e) {
      (U[e] *= e) %= MO;
    }
  }

  // assert(N <= 500);

  // memset(dp, 0, sizeof(dp));
  // dp[0][0] = 1;
  // for (int c = 0; c <= C; ++c) {
  //   for (int e = 0; e <= E; ++e) {
  //     if (e < E) {
  //       for (int u = 0; c + u <= C; ++u) {
  //         (dp[c + u][e + 1] += (dp[c][e] * (E - e) % MO * comb(C - c, u) % MO * fact[u] % MO * comb(c + u + e + 1, u + 1) % MO)) %= MO;
  //       }
  //     }
  //   }
  // }

  // Int res = 0;
  // for (int c = 0; c <= C; ++c) {
  //   Int pat = fact[C - c] * fact[C - c] % MO;
  //   (res += dp[c][E] * pat % MO * comb(C + E, C - c) % MO) %= MO;
  // }

  printf("%lld\n", res);

  return 0;
}
