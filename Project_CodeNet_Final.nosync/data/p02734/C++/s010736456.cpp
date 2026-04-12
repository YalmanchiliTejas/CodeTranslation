#include <cstdio>
#include <cstring>

const int MaxN = 3000, MaxM = 3000;
const int Mod = 998244353;

int N, M, Ans;
int A[MaxN + 5];
int F[MaxM + 5], Buc[MaxM + 5];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline int mul(int x, int y) { return 1LL * x * y % Mod; }
inline void inc(int &x, int y = 1) { x = add(x, y); }

void init() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
}

void fun(int l, int r) {
  if (l == r) {
    if (A[l] == M) inc(Ans);
    return;
  }
  int m = (l + r) >> 1;
  fun(l, m);
  fun(m + 1, r);
  memset(Buc, 0, sizeof Buc);
  memset(F, 0, sizeof F);
  F[0] = 1;
  for (int i = m; i >= l; --i) {
    for (int j = M; j >= A[i]; --j) inc(F[j], F[j - A[i]]);
    for (int j = 0; j <= M; ++j) inc(Buc[j], F[j]);
  }
  memset(F, 0, sizeof F);
  F[0] = 1;
  for (int i = m + 1; i <= r; ++i) {
    for (int j = M; j >= A[i]; --j) inc(F[j], F[j - A[i]]);
    for (int j = 0; j <= M; ++j) inc(Ans, mul(F[j], Buc[M - j]));
  }
}

void solve() {
  fun(1, N);
  printf("%d\n", Ans);
}

int main() {
  init();
  solve();
  return 0;
}