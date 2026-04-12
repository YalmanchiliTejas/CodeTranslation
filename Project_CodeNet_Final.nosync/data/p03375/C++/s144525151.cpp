#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

void add(int &a, int b, int mod) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int mul(int a, int b, int mod) {
  return (int)((long long)a * b % mod);
}

int pw(int a, int b, int mod) {
  int res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = mul(res, a, mod);
    }
    a = mul(a, a, mod);
    b /= 2;
  }
  return res;
}

const int N = 3'009;

int c[N][N];
int f[N][N];

int main() {
  int n, mod;
  scanf("%d %d", &n, &mod);
  memset(c, 0, sizeof c);
  for (int i = 0; i <= n; ++i) {
    c[i][0] = 1;
    c[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      c[i][j] = c[i - 1][j];
      add(c[i][j], c[i - 1][j - 1], mod);
    }
  }
  memset(f, 0, sizeof f);
  f[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      add(f[i + 1][j], mul(f[i][j], j + 1, mod), mod);
      add(f[i + 1][j + 1], f[i][j], mod);
    }
  }
  int ans = pw(2, pw(2, n, mod - 1), mod);
  for (int i = 1; i <= n; ++i) {
    int cur = 0;
    for (int j = 0; j <= i; ++j) {
      add(cur, mul(f[i][j], pw(2, (n - i) * j, mod), mod), mod);
    }
    cur = mul(cur, c[n][i], mod);
    cur = mul(cur, pw(2, pw(2, n - i, mod - 1), mod), mod);
    if (i % 2 == 1) {
      add(ans, mod - cur, mod);
    } else {
      add(ans, cur, mod);
    }
  }
  printf("%d\n", ans);
}
