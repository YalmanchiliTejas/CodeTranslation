#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define isNum(a) (a >= '0' && a <= '9')
#define SP putchar(' ')
#define EL putchar('\n')
#define File(a) freopen(a ".in", "r", stdin), freopen(a ".out", "w", stdout)

template<class T>
void read(T&);
template<class T>
void write(const T&);

typedef long long ll;
typedef unsigned long long ull;
typedef const long long & cll;
typedef const int & ci;
typedef std::pair<int, int> pii;
const int iinf = 2147483647;
const ll llinf = 9223372036854775807ll;
using std::min;
using std::max;
using std::abs;
using std::sort;

const int N = 8005;
const int M = 205;
const int P = 20000;
const int Mod = 998244353, gm = 3;

class Poly {
public:
  int *a, deg;
  Poly() {
    a = new int[P];
    memset(a, 0, sizeof(int) * (P - 1));
    deg = 0;
  }
  void NTT(int lim, bool opt);
};
int r[P];

int pow(int a, int b, int m);
int C(int n, int m);

Poly f, g;
int fac[N], ifac[N];
int dp[N][M];
int n, m;

int main () {
  read(n), read(m);
  f.deg = g.deg = n;
  int lim = 1;
  while (lim <= (n << 1)) {
    lim <<= 1;
  }
  for (int i = 0; i < lim; ++i) {
    r[i] = (r[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
  }
  fac[0] = 1;
  for (int i = 1; i <= n + 2; ++i) {
    fac[i] = fac[i - 1] * 1ll * i % Mod;
  }
  ifac[n + 2] = pow(fac[n + 2], Mod - 2, Mod);
  for (int i = n + 1; i >= 0; --i) {
    ifac[i] = ifac[i + 1] * 1ll * (i + 1) % Mod;
  }
  dp[0][0] = 1;
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      f.a[i] = ifac[i + 2];
    }
    for (int i = 0; i <= n; ++i) {
      g.a[i] = dp[i][j - 1] * 1ll * ifac[i] % Mod;
    }
    f.NTT(lim, false), g.NTT(lim, false);
    for (int i = 0; i < lim; ++i) {
      f.a[i] = f.a[i] * 1ll * g.a[i] % Mod;
    }
    f.NTT(lim, true);
    for (int i = 0; i <= n; ++i) {
      dp[i][j] = fac[i + 2] * 1ll * f.a[i] % Mod;
      dp[i][j] = (dp[i][j] + (1 + i + C(i, 2)) * 1ll * dp[i][j - 1] % Mod) % Mod;
    }
    for (int i = 0; i < lim; ++i) {
      f.a[i] = g.a[i] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = (ans + C(n, i) * 1ll * dp[i][m] % Mod) % Mod;
  }
  write(ans), EL;
  return 0;
}

template<class T>
inline void read(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!isNum(ch)) {
    if (ch == '-') {
      flag = -1;
    }
    ch = getchar();
  }
  while (isNum(ch)) {
    k = (k << 1) + (k << 3) + ch - '0';
    ch = getchar();
  }
  Re = flag * k;
}
template<class T>
inline void write(const T &Wr) {
  if (Wr < 0) {
    putchar('-');
    write(-Wr);
  } else {
    if (Wr < 10) {
      putchar(Wr + '0');
    } else {
      write(Wr / 10);
      putchar((Wr % 10) + '0');
    }
  }
}

void Poly::NTT(int lim, bool opt) {
  for (int i = 0; i < lim; ++i) {
    if (i < r[i]) {
      std::swap(a[i], a[r[i]]);
    }
  }
  for (int l = 1; l < lim; l <<= 1) {
    int gn = pow(gm, (Mod - 1) / (l << 1), Mod);
    for (int i = 0; i < lim; i += (l << 1)) {
      for (int j = 0, gw = 1; j < l; ++j, gw = gw * 1ll * gn % Mod) {
        int x = a[i | j], y = a[i | j | l] * 1ll * gw % Mod;
        a[i | j] = (x + y) % Mod;
        a[i | j | l] = (x - y + Mod) % Mod; 
      }
    }
  }
  if (opt) {
    std::reverse(a + 1, a + lim);
    int iv = pow(lim, Mod - 2, Mod);
    for (int i = 0; i < lim; ++i) {
      a[i] = a[i] * 1ll * iv % Mod;
    }
  }
}
int pow(int a, int b, int m) {
  int ans = 1, now = a;
  while (b) {
    if (b & 1) {
      ans = ans * 1ll * now % m;
    }
    now = now * 1ll * now % m;
    b >>= 1;
  }
  return ans;
}
int C(int n, int m) {
  return fac[n] * 1ll * ifac[m] % Mod * ifac[n - m] % Mod;
}
