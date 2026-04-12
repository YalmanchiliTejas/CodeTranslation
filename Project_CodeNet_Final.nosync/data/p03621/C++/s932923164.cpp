#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 998244353, gen = 3;

inline int Mul(int a, int b) {
  return (long long)a * b % mod;
}

inline int Add(int a) {
  return a >= mod ? a - mod : a;
}

inline int Sub(int a) {
  return a < 0 ? a + mod : a;
}

int Pow(int a, int b) {
  int c = 1;
  for (; b; b >>= 1) {
    if (b & 1) c = Mul(c, a);
    a = Mul(a, a);
  }
  return c;
}

void FFT(int *a, int n) {
  for (int i = 0; i < 1 << n; ++i) {
    int j = 0, x = i;
    for (int k = 0; k < n; ++k) {
      j = (j << 1) | (x & 1);
      x >>= 1;
    }
    if (i < j) {
      swap(a[i], a[j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    int root = Pow(gen, (mod - 1) / (2 << i));
    for (int j = 0; j < 1 << n; j += 2 << i) {
      int w = 1, *l = a + j, *r = a + j + (1 << i);
      for (int k = 0; k < 1 << i; ++k, w = Mul(w, root)) {
        int t = Mul(w, r[k]);
        r[k] = Sub(l[k] - t);
        l[k] = Add(l[k] + t);
      }
    }
  }
}

void IFFT(int *a, int n) {
  reverse(a + 1, a + (1 << n));
  FFT(a, n);
  int inv = Pow(1 << n, mod - 2);
  for (int i = 0; i < 1 << n; ++i) {
    a[i] = Mul(a[i], inv);
  }
}

void Conv(int *a, int *b, int n) {
  FFT(a, n);
  if (a != b) {
    FFT(b, n);
  }
  for (int i = 0; i < 1 << n; ++i) {
    a[i] = Mul(a[i], b[i]);
  }
  if (a != b) {
    IFFT(b, n);
  }
  IFFT(a, n);
}

void PowC(int *a, int *b, int len, int exp) {
  int n = 0;
  while (1 << n < len << 1) {
    ++n;
  }
  memset(b, 0, (1 << n) * sizeof(int));
  b[0] = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) {
      Conv(b, a, n);
      for (int k = len; k < 1 << n; ++k) {
        b[k] = 0;
      }
    }
    Conv(a, a, n);
    for (int k = len; k < 1 << n; ++k) {
      a[k] = 0;
    }
  }
}

const int maxn = 10000;

char s1[maxn + 1], s2[maxn + 1];
int fact[maxn + 1], ifact[maxn + 1];
int p[1 << 15], q[1 << 15];

int main(void) {
  scanf("%s%s", s1, s2);
  int a = 0, b = 0;
  for (int i = 0; s1[i]; ++i) {
    if (s1[i] == '1' && s2[i] == '1') {
      ++a;
    } else if (s1[i] == '1') {
      ++b;
    }
  }
  fact[0] = 1;
  for (int i = 1; i <= a + b; ++i) {
    fact[i] = Mul(fact[i - 1], i);
  }
  ifact[a + b] = Pow(fact[a + b], mod - 2);
  for (int i = a + b; i >= 1; --i) {
    ifact[i - 1] = Mul(ifact[i], i);
  }
  for (int i = 0; i <= a; ++i) {
    p[i] = ifact[i + 1];
  }
  PowC(p, q, a + 1, b);
  int sum = 0;
  for (int i = 0; i <= a; ++i) {
    sum = Add(sum + q[i]);
  }
  sum = Mul(sum, Mul(fact[a + b], Mul(fact[a], fact[b])));
  printf("%d\n", sum);
  return 0;
}
