#include<bits/stdc++.h>
#define rint register int
using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
  x = 0;char c = getchar();bool f = 0;
  for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
  if (f) x = -x;
}

namespace {
  const int mo = 998244353;
  inline int add(int x, int y) {
    if((x += y) >= mo) x -= mo;
    return x;
  }
  inline int sub(int x, int y) {
    if((x -= y) < 0) x += mo;
    return x;
  }
  inline int mul(int x, int y) {
    return 1LL * x * y % mo;
  }
  inline int pw(int a, int k, int mo) {
    int ans = 1;
    for(; k; k >>=1, a = mul(a, a))
      if(k & 1) ans = mul(ans, a);
    return ans;
  }
}
const int N = 7e4 + 233;
int fac[N], fac_inv[N];
int n, a, b;
char s[N], t[N];
inline void init(void) {
  fac[0] = 1;
  for (int i = 1; i < N; i ++)
    fac[i] = mul(fac[i - 1], i);
  fac_inv[N - 1] = pw(fac[N - 1], mo - 2, mo);
  for (int i = N - 2; i >= 0; i --)
    fac_inv[i] = mul(fac_inv[i + 1], i + 1);
}

namespace Poly {
  const int G = 3;
  int rev[N], a[N], b[N], ans[N];
  int n, m;
  inline void FFT(int *p, int fff, int n) {
    for (int i = 0; i < n; i ++)
      if (i < rev[i])
        swap(p[i], p[rev[i]]);
    for (int l = 2; l <= n; l <<= 1) {
      int w = pw(G, (mo - 1) / l, mo);
      if (fff == -1) w = pw(w, mo - 2, mo);
      for (int *a = p, m = l >> 1; a != p + n; a += l) {
        for (int k = 0, wn = 1; k < m; k ++, wn = mul(wn, w)) {
          int x = a[k], y = mul(a[k + m], wn);
          a[k] = add(x, y);
          a[k + m] = sub(x, y);
        }
      }
    }
    if (fff == -1) {
      int tmp = pw(n, mo - 2, mo);
      for (int i = 0; i < n; i ++)
        p[i] = mul(p[i], tmp);
    }
  }
  inline void debug(int a[], int n) {
    for (int i = 0; i < n; i ++)
      cout << a[i] << " "; puts("");
  }
  inline void Mul(int a[], int b[], int ans[]) {
    static int ta[N], tb[N];
    for (int i = 0; i < m; i ++)
      ta[i] = a[i], tb[i] = b[i];
    FFT(ta, 1, m); FFT(tb, 1, m);
    for (int i = 0; i < m; i ++) {
      ans[i] = mul(ta[i], tb[i]);
    }
    FFT(ans, -1, m);
    for (int i = n + 1; i < m; i ++)
      ans[i] = 0;
  }
  inline void init(int _n) {
    n = _n;
    a[0] = 1;
    for (int i = 0; i <= n; i ++)
      b[i] = fac_inv[i + 1];
    int L = -1;
    for (m = 1; m <= n + n + 1; m <<= 1) L ++;
    for (int i = 0; i < m; i ++)
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << L);
  }
  inline void fastpow(int k) {
    // debug(b, m);
    // debug(a, m);
    for (; k; k >>= 1, Mul(b, b, b))
      if (k & 1) Mul(a, b, a);
  }  
}

inline int doit(void) {
  Poly::init(a);
  Poly::fastpow(b);
  int ans = 0;
  for (int i = 0; i <= a; i ++)
    ans = add(ans, Poly::a[i]);
  ans = mul(ans, mul(fac[a + b], mul(fac[a], fac[b])));
  return ans;
}

main(void) {
  init();
  scanf("%s%s", s + 1, t + 1);
  n = (int) strlen(s + 1);
  for (int i = 1; i <= n; i ++) {
    a += s[i] == '1' && t[i] == '1';
    b += s[i] == '1' && t[i] == '0';
  }
  cout << doit() << "\n";
}
