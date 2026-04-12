#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100000 + 5;

int N;
int A[MaxN], D[MaxN];

struct BIT {
  int t[MaxN];
  inline int lowbit(int i) { return i & -i; }

  inline void update(int x, int v) {
    for (int i = x; i <= N; i += lowbit(i))
      t[i] = max(t[i], v);
  }

  inline int query(int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      res = max(res, t[i]);
    return res;
  }
} T;

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), D[i] = A[i];
  sort(D + 1, D + 1 + N);
  for (int i = 1; i <= N; ++i) A[i] = lower_bound(D + 1, D + 1 + N, A[i]) - D;
}

void solve() {
  for (int i = 1; i <= N; ++i)
    T.update(N - A[i] + 1, T.query(N - A[i] + 1) + 1);
  printf("%d\n", T.query(N));
}

int main() {
  init();
  solve();
  return 0;
}