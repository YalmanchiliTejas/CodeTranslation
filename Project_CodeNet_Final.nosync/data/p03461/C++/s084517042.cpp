#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int d[N][N], f[N][N];
struct data {
  int x, y, w;
} g[N * N * 10];
int dx[N], dy[N];

int check(int x, int y) {
  int ans = 1e9;
  for(int i = 0; i <= 100; ++i)
   for(int j = 0; j <= 100; ++j)
    ans = min(ans, i * x + j * y + f[i][j]);
  return ans;
}

int main() {
  int A, B;
  cin >> A >> B;
  for(int i = 1; i <= A; ++i)
    for(int j = 1; j <= B; ++j)
      scanf("%d", &d[i][j]);
  for(int i = 0; i <= 100; ++i)
    for(int j = 0; j <= 100; ++j) {
      for(int k = 1; k <= A; ++k)
       for(int t = 1; t <= B; ++t)
        f[i][j] = max(f[i][j], d[k][t] - i * k - j * t);
    }
  for(int i = 1; i <= A; ++i)
    for(int j = 1; j <= B; ++j) {
      if(check(i, j) != d[i][j]) {
        puts("Impossible");
        exit(0);
      }
    }
  puts("Possible");
  int tot = 0, res = 0;
  int S = ++tot;
  dx[0] = S;
  for(int i = 1; i <= 100; ++i) {
    dx[i] = ++tot;
    g[++res] = (data){dx[i - 1], dx[i], -1};
  }
  int T = ++tot;
  dy[0] = T;
  for(int i = 1; i <= 100; ++i) {
    dy[i] = ++tot;
    g[++res] = (data){dy[i], dy[i - 1], -2};
  }
  for(int i = 0; i <= 100; ++i)
    for(int j = 0; j <= 100; ++j) {
      g[++res] = (data){dx[i], dy[j], f[i][j]};
    }
  printf("%d %d\n", tot, res);
  for(int i = 1; i <= res; ++i) {
    printf("%d %d ", g[i].x, g[i].y);
    if(g[i].w < 0) {
      if(g[i].w == -1) puts("X");
      else puts("Y");
    } else printf("%d\n", g[i].w);
  }
  printf("%d %d\n", S, T);
  return 0;
}