// Copyright lzt
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<queue>
#include<string>
#include<ctime>
using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<long long, long long> pll;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, j, k)  for (register int i = (int)(j); i <= (int)(k); i++)
#define rrep(i, j, k) for (register int i = (int)(j); i >= (int)(k); i--)
#define Debug(...) fprintf(stderr, __VA_ARGS__)

inline ll read() {
  ll x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  return x * f;
}

const int maxn = 3030;
int n;
int a[maxn];
ll f[maxn][maxn];

void work() {
  n = read();
  rep(i, 1, n) a[i] = read();
  rep(l, 1, n) {
    rep(i, 1, n) {
      int j = i + l - 1;
      if (j > n) break;
      f[i][j] = max(a[j] - f[i][j - 1], a[i] - f[i + 1][j]);
    }
  }
  printf("%lld\n", f[1][n]);
}

int main() {
  #ifdef LZT
    freopen("in", "r", stdin);
  #endif

  work();

  #ifdef LZT
    Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
  #endif
}
