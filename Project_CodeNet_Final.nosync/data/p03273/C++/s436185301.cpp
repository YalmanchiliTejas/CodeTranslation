#include <stdio.h>

char g[110][110];
int n, m, bad_row[110], bad_col[110];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", g[i] + 1);
  }
  for (int i = 1; i <= n; ++i) {
    int bad = 1;
    for (int j = 1; j <= m; ++j) {
      if (g[i][j] == '#') {
        bad = 0;
        break;
      }
    }
    bad_row[i] = bad;
  }
  for (int j = 1; j <= m; ++j) {
    int bad = 1;
    for (int i = 1; i <= n; ++i) {
      if (g[i][j] == '#') {
        bad = 0;
        break;
      }
    }
    bad_col[j] = bad;
  }
  for (int i = 1; i <= n; ++i) {
    if (bad_row[i]) continue;
    for (int j = 1; j <= m; ++j) {
      if (bad_col[j]) continue;
      putchar(g[i][j]);
    }
    puts("");
  }
  return 0;
}

