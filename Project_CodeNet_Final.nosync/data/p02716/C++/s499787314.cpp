#include <bits/stdc++.h>
#define RI register int
typedef long long LL;
#define int LL

#define FILEIO(name) freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);

using namespace std;

char buf[1000000], *p1 = buf, *p2 = buf;
inline char gc() {
  if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin);
  return p1 == p2 ? EOF : *(p1++);
}
template <class T> inline void read(T &n) {
  n = 0; RI ch = gc(), f;
  while ((ch < '0' || ch > '9') && ch != '-') ch = gc();
  f = (ch == '-' ? ch = gc(), -1 : 1);
  while (ch >= '0' && ch <= '9') n = n * 10 + (ch ^ 48), ch = gc();
  n *= f;
}

int const MAXN = 2e5 + 5;
int a[MAXN];
int f[2][MAXN][2];

signed main() {
  
#ifdef LOCAL
  FILEIO("a");
#endif

  int n; read(n);
  for (RI i = 1; i <= n; ++i) read(a[i]);
  memset(f, -0x7f, sizeof(f));
  f[0][0][0] = 0;
  int cur = 0, last = 1;
  for (RI i = 1; i <= n; ++i) {
    swap(cur, last);
    int R = (i + 1) / 2 + 1, L = (n / 2) - ((n - i) / 2) - 1;
    for (RI j = R; j >= L; --j) {
      f[cur][j][0] = max(f[last][j][0], f[last][j][1]);
      f[cur][j][1] = f[last][j - 1][0] + a[i];
    }
  }
  printf("%lld\n", max(f[cur][n / 2][0], f[cur][n / 2][1]));

  return 0;
}

// created by Daniel yuan
