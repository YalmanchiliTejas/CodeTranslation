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

struct Ev {
  int p, v, l;
  bool isr;
};

long long T[1 << 19], U[1 << 19];

void tupd(int p, int L, int R, int l, int r, long long v) {
  if (L == l && R == r) {
    T[p] += v;
    U[p] += v;
    return;
  }
  auto M = (L + R) >> 1;
  auto pl = p << 1;
  auto pr = pl + 1;
  if (U[p]) {
    T[pl] += U[p];
    U[pl] += U[p];
    T[pr] += U[p];
    U[pr] += U[p];
    U[p] = 0;
  }
  if (r <= M)
    tupd(pl, L, M, l, r, v);
  else if (l >= M)
    tupd(pr, M, R, l, r, v);
  else {
    tupd(pl, L, M, l, M, v);
    tupd(pr, M, R, M, r, v);
  }
  T[p] = max(T[pl], T[pr]);
}

long long tqry(int p, int L, int R, int l, int r) {
  if (L == l && R == r)
    return T[p];
  auto M = (L + R) >> 1;
  auto pl = p << 1;
  auto pr = pl + 1;
  if (U[p]) {
    T[pl] += U[p];
    U[pl] += U[p];
    T[pr] += U[p];
    U[pr] += U[p];
    U[p] = 0;
  }
  if (r <= M)
    return tqry(pl, L, M, l, r);
  if (l >= M)
    return tqry(pr, M, R, l, r);
  return max(tqry(pl, L, M, l, M), tqry(pr, M, R, M, r));
}

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  auto R = 1;
  while (R <= N)
    R <<= 1;
  auto P = 0;
  static Ev A[400000];
  for (auto i = 0; i < M; ++i) {
    int l, r, a;
    scanf("%d%d%d", &l, &r, &a);
    A[P++] = {l, a, l, false};
    A[P++] = {r, a, l, true};
  }
  sort(A, A + P, [](const Ev& a, const Ev& b) {
    return a.p != b.p ? a.p < b.p : a.isr < b.isr;
  });
  auto j = 0;
  auto res = 0ll;
  for (auto i = 1; i <= N; ++i) {
    while (j < P && A[j].p == i && !A[j].isr) {
      tupd(1, 0, R, 0, A[j].l, A[j].v);
      ++j;
    }
    auto f = tqry(1, 0, R, 0, i);
    res = max(res, f);
    tupd(1, 0, R, i, i + 1, f);
    while (j < P && A[j].p == i) {
      tupd(1, 0, R, 0, A[j].l, -A[j].v);
      ++j;
    }
  }
  printf("%lld\n", res);
  return 0;
}
