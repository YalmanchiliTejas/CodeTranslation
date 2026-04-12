#include <bits/stdc++.h>

using namespace std;

int s[42][42];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c = getchar();
      while (c <= 32) c = getchar();
      s[i][j] = c;
    }
  }
  if (s[0][0] != '#') {
    puts("Impossible");
    return 0;
  }
  for (int i = 0, j = 0; i + 1 < n || j + 1 < m; ) {
    s[i][j] = '.';
    if (i + 1 < n && s[i + 1][j] == '#') {
      i++;
    } else if (j + 1 < m && s[i][j + 1] == '#') {
      j++;
    } else {
      puts("Impossible");
      return 0;
    }
  }
  s[n - 1][m - 1] = '.';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#') {
        puts("Impossible");
        return 0;
      }
    }
  }
  puts("Possible");
}
