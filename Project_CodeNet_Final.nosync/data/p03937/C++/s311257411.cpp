#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 8;

int n, m;
char mp[maxn][maxn + 1];

int main(void) {
  scanf("%d%d", &n, &m);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", mp[i]);
    for (int j = 0; j < m; ++j) cnt += (mp[i][j] == '#');
  }
  if (cnt != n + m - 1) {
    puts("Impossible");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == '#' && !(i == n - 1 && j == m - 1)) {
        if ((i == n - 1 || mp[i + 1][j] == '.') && (j == m - 1 || mp[i][j + 1] == '.')) {
          puts("Impossible");
          return 0;
        }
      }
    }
  }
  puts("Possible");
  return 0;
}
