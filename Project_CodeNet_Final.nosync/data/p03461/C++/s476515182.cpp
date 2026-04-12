#include <algorithm>
#include <cstdio>
const int N = 12;
const int x = 0x7fffffff;
const int y = 0x7ffffffe;
int d[N][N];
bool v[N][N];
int X[1000], Y[1000], S, T, cnt, m;
int from[1000000], to[1000000], cost[1000000];
inline void addEdge(int x, int y, int z) {
  cost[m] = z;
  from[m] = x;
  to[m++] = y;
}
int main() {
  int A, B;
  scanf("%d%d", &A, &B);
  int xx = 0, yy = 0;
  for (int i = 1; i <= A; ++i)
    for (int j = 1; j <= B; ++j) {
      scanf("%d", &d[i][j]);
      xx = std::max(xx, d[i][j] / i);
      yy = std::max(yy, d[i][j] / j);
      v[i][j] = 0;
    }
  cnt = 0;
  m = 0;
  for (int i = 0; i <= xx; ++i) X[i] = cnt++;
  for (int i = 0; i <= yy; ++i) Y[i] = cnt++;
  S = X[0];
  T = Y[0];
  for (int i = 0; i < xx; ++i) addEdge(X[i], X[i + 1], x);
  for (int i = 0; i < yy; ++i) addEdge(Y[i + 1], Y[i], y);
  for (int i = 0; i <= xx; ++i)
    for (int j = 0; j <= yy; ++j) {
      int ans = 0;
      for (int a = 1; a <= A; ++a)
        for (int b = 1; b <= B; ++b)
          ans = std::max(ans, d[a][b] - i * a - j * b);
      if (ans < 0 || ans > 100) continue;
      addEdge(X[i], Y[j], ans);
      for (int a = 1; a <= A; ++a)
        for (int b = 1; b <= B; ++b)
          if (d[a][b] == i * a + j * b + ans)
            v[a][b] = true;
    }
  for (int a = 1; a <= A; ++a)
    for (int b = 1; b <= B; ++b)
      if (!v[a][b]) return puts("Impossible") & 0;
  puts("Possible");
  printf("%d %d\n", cnt, m);
  for (int i = 0; i < m; ++i) {
    printf("%d %d ", 1 + from[i], 1 + to[i]);
    if (cost[i] == x) printf("X");
    else if (cost[i] == y) printf("Y");
    else printf("%d", cost[i]);
    printf("\n");
  }
  printf("%d %d\n", 1 + S, 1 + T);
  return 0;
}
