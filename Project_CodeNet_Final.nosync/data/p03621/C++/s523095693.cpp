#include <bits/stdc++.h>
using namespace std;

typedef vector<int> poly;

const int mod = 998244353, N = 51000;

namespace {
  inline int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
  inline int sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }
  inline int mul(int x, int y) { return 1LL * x * y % mod; }
  inline int kissme(int x, int y) {
    int c = 1;
    while(y) {
      if(y & 1) {
	c = mul(c, x);
      }
      x = mul(x, x);
      y >>= 1;
    }
    return c;
  }
}

namespace ntt {
  int rev[N << 1], L, l;

  void pre(int n) {
    for(l = 0; (1 << l) < n; l++);
    L = 1 << l;
    for(int i = 0; i < L; i++) {
      rev[i] = rev[i >> 1] >> 1 | (i & 1) << (l - 1);
    }
  }

  void dft(int *a) {
    for(int i = 0; i < L; i++) {
      if(rev[i] > i) {
	swap(a[i], a[rev[i]]);
      }
    }
    for(int i = 1; i < L; i <<= 1) {
      int wn = kissme(3, (mod - 1) / (i << 1));
      for(int j = 0; j < L; j += i << 1) {
	int *f = a + j, *g = a + i + j;
	for(int k = 0, w = 1; k < i; k++, w = mul(w, wn)) {
	  int u = f[k], v = mul(w, g[k]);
	  f[k] = add(u, v);
	  g[k] = sub(u, v);
	}
      }
    }
  }

  void idft(int *a) {
    reverse(a + 1, a + L);
    int inv = kissme(L, mod - 2);
    dft(a);
    for(int i = 0; i < L; i++) {
      a[i] = mul(a[i], inv);
    }
  }
}

int n;
char a[N], b[N];

poly operator * (poly a, poly b) {
  using namespace ntt;
  pre(a.size() + b.size() - 1);
  a.resize(L), b.resize(L);
  dft(&a[0]), dft(&b[0]);
  for(int i = 0; i < L; i++) {
    a[i] = mul(a[i], b[i]);
  }
  idft(&a[0]);
  a.resize(n);
  return a;
}

int main(void) {
  scanf("%s%s", a, b);
  n = strlen(a);
  int x = 0, y = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] ^ b[i]) {
      x++;
    } else if(a[i] == 49) {
      y++;
    }
  }
  x >>= 1;
  n = y + 1;
  poly f(1, 1), g(n), fac(x + y + 1, 1);
  for(int i = 1; i <= x + y; i++) {
    fac[i] = mul(fac[i - 1], i);
  }
  for(int i = 0; i < n; i++) {
    g[i] = kissme(fac[i + 1], mod - 2);
  }
  for(int k = x; k; k >>= 1, g = g * g) {
    if(k & 1) {
      f = f * g;
    }
  }
  int ans = 0;
  f.resize(n);
  for(int i = 0; i < n; i++) {
    ans = add(ans, f[i]);
  }
  cout << mul(ans, mul(fac[x], mul(fac[y], fac[x + y]))) << endl;
  return 0;
}
