#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>

#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define FILLA(a, x) memset((a), (x), sizeof (a))
#define COPYA(a, b) memcpy((b), (a), sizeof (a))

using namespace std;

typedef long long li;
typedef unsigned long long lu;
const li infl = ~0LLU >> 2;

template <class T>
inline void Min(T &x, T y) {
  if (y < x) x = y;
}
template <class T>
inline void Max(T &x, T y) {
  if (y > x) x = y;
}

int mod;
inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline int Sub(int x) { return x < 0 ? x + mod : x; }
inline void Sub(int &x, int y) { x -= y; if (x < 0) x += mod; }
inline int Mul(int x, int y) { return (int)((li)x * y % mod); }
inline int Mul(int x, int y, int z) { return Mul(x, Mul(y, z)); }
int Pow(int x, int y) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = Mul(z, x);
    x = Mul(x, x);
  }
  return z;
}
int Inv(int x) {
  return Pow(x, mod - 2);
}

// ----------------------------------------

const int maxn = 3000;
int n;
int S[maxn + 1][maxn + 2];
int bin[maxn + 1][maxn + 1];
int pw2[maxn * maxn + 1];

int PowEx(int x, int y, int mod) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) {
      z = (int)((li)z * x % mod);
    }
    x = (int)((li)x * x % mod);
  }
  return z;
}

int main(void) {
  scanf("%d%d", &n, &mod);
  for (int i = 0; i <= n; ++i) {
    S[i][0] = (i == 0);
    bin[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      S[i][j] = Add(S[i - 1][j - 1] + Mul(S[i - 1][j], j));
      bin[i][j] = Add(bin[i - 1][j - 1] + bin[i - 1][j]);
    }
  }
  pw2[0] = 1;
  for (int i = 1; i <= n * n; ++i) {
    pw2[i] = Add(pw2[i - 1] << 1);
  }

  int ans = 0;
  for (int m = 0; m <= n; ++m) {
    int coeff = Mul(bin[n][m], Pow(2, PowEx(2, n - m, mod - 1)));
    int sum = 0;
    for (int k = 0; k <= m; ++k) {
      Add(sum, Mul(Add(S[m][k] + Mul(k + 1, S[m][k + 1])), pw2[k * (n - m)]));
    }
    if (m & 1) {
      Sub(ans, Mul(sum, coeff));
    } else {
      Add(ans, Mul(sum, coeff));
    }
  }
  printf("%d\n", ans);

  return 0;
}
