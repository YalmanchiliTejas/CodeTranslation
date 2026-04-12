#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

inline int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int x) {
  return power(x, md - 2);
}

const int gen = 3;
int powers[423456];

void fft(vector <int> &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    int j = 0;
    int x = i, y = n - 1;
    while (y > 0) {
      j = (j << 1) + (x & 1);
      x >>= 1;
      y >>= 1;
    }
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 1; len < n; len *= 2) {
    int step = n / 2 / len;
    for (int i = 0; i < n; i += 2 * len) {
      int pos = 0;
      for (int j = 0; j < len; j++) {
        int w = powers[pos];
        int u = a[i + j];
        int v = mul(a[i + j + len], w);
        a[i + j] = u + v;
        if (a[i + j] >= md) a[i + j] -= md;
        a[i + j + len] = u - v;
        if (a[i + j + len] < 0) a[i + j + len] += md;
        pos += step;
      }
    }
  }
}

vector <int> multiply(vector <int> a, vector <int> b) {
  int an = a.size();
  int bn = b.size();
  int nn = 1;
  while (nn < 2 * an || nn < 2 * bn) nn <<= 1;
  int root = power(gen, (md - 1) / nn);
  powers[0] = 1;
  for (int i = 1; i <= nn; i++) {
    powers[i] = mul(powers[i - 1], root);
  }
  a.resize(nn);
  b.resize(nn);
  fft(a);
  fft(b);
  for (int i = 0; i < nn; i++) {
    a[i] = mul(a[i], b[i]);
  }
  reverse(++a.begin(), a.end());
  fft(a);
  int inv = power(nn, md - 2);
  for (int i = 0; i < nn; i++) {
    a[i] = mul(a[i], inv);
  }
  a.resize(an);
  return a;
}

const int N = 123456;

int fact[N], inv_fact[N];
char s1[N], s2[N];

int main() {
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = inv(fact[i]);
  }
  int n, m;
//  scanf("%d %d", &n, &m);
  scanf("%s", s1);
  scanf("%s", s2);
  n = m = 0;
  for (int i = 0; s1[i]; i++) {
    if (s1[i] == '1') {
      if (s2[i] == '0') {
        n++;
      } else {
        m++;
      }
    }
  }
  vector <int> p(m + 1);
  for (int k = 0; k <= m; k++) {
    p[k] = inv_fact[k + 1];
  }
  vector <int> res(m + 1, 0);
  res[0] = 1;
  int x = n;
  while (x > 0) {
    if (x & 1) {
      res = multiply(res, p);
    }
    p = multiply(p, p);
    x >>= 1;
  }
  int ans = 0;
  for (int j = 0; j <= m; j++) {
    add(ans, res[j]);
  }
  ans = mul(ans, mul(fact[n + m], mul(fact[n], fact[m])));
  printf("%d\n", ans);
  cerr << "time = " << clock() << " ms" << endl;
  return 0;
}
