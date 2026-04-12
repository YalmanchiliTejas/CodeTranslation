#include <cstdio>

const int MaxN = 3000;
const int Mod = 998244353;

int N, M;
int A[MaxN + 5];
int F[MaxN + 5][3];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline void inc(int &x, int y = 1) { x = add(x, y); }

void init() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
}

void solve() {
  F[0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j <= M; ++j) inc(F[j][1], F[j][0]);
    for (int j = M; j >= A[i]; --j) inc(F[j][1], F[j - A[i]][1]);
    for (int j = 0; j <= M; ++j) inc(F[j][2], F[j][1]);
  }
  printf("%d\n", F[M][2]);
}

int main() {
  init();
  solve();
  return 0;
}