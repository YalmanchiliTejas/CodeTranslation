#include <cstdio>

const int N = 10;

int n, m;
char s[N][N];

int f[N][N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf(" %s", s[i] + 1);
  f[1][0] = 1;
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      f[i][j] = (s[i][j] == '#' ? (f[i - 1][j] + f[i][j - 1]) : 0), cnt += (s[i][j] == '#');
  puts(f[n][m] == 1 && cnt == n + m - 1 ? "Possible" : "Impossible");
  return 0;
}
