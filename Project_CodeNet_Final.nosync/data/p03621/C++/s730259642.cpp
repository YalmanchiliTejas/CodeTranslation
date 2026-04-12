#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int mod = 998244353;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

namespace NTT {
  int g = 0; // !

  void findPrimitiveRoot() {
    if (g) return;

    vector<int> d;
    for (int i = 2; i*i <= mod-1; ++i)
      if ((mod-1) % i == 0) d.push_back(i), d.push_back((mod-1)/i);
    for (g = 2; ; g++) {
      bool ok = true;
      for (int x: d) ok &= powmod(g, x) != 1;
      if (ok) break;
    }
  }
  
  void transform(int* a, int* z, int* omega, int m, int N) {
    if (m == 1) {
      z[0] = a[0];
    } else {
      int s = N/m;
      m /= 2;
 
      transform(a, z, omega, m, N);
      transform(a+s, z+m, omega, m, N);
 
      REP(i, m) {
        int c = mul(omega[s*i], z[m+i]);
        z[m+i] = sub(z[i], c);
        z[i] = add(z[i], c);
      }
    }
  }

  vector<int> fft(vector<int>& a) {
    findPrimitiveRoot();

    int N = a.size();
    int w = powmod(g, (mod-1) / N);
    vector<int> omega(N);
    omega[0] = 1;
    FOR(i, 1, N) omega[i] = mul(omega[i-1], w);

    vector<int> z(N);
    transform(a.data(), z.data(), omega.data(), N, N);
    return z;
  }
  
  vector<int> ifft(vector<int>& a) {
    findPrimitiveRoot();

    int N = a.size();
    int wi = powmod(powmod(g, (mod-1)/N), mod-2);
    vector<int> omega(N);
    omega[0] = 1;
    FOR(i, 1, N) omega[i] = mul(omega[i-1], wi);

    vector<int> z(N);
    transform(a.data(), z.data(), omega.data(), N, N);
    
    int invN = powmod(N, mod - 2);
    REP(i, N) z[i] = mul(z[i], invN);
    return z;
  }
  
  vector<int> mult(vector<int> a, vector<int> b) {
    int N = a.size() + b.size();
    while (N & (N-1)) ++N;

    a.resize(N, 0);
    b.resize(N, 0);

    vector<int> ta = fft(a);
    vector<int> tb = fft(b);
    REP(i, N) ta[i] = mul(ta[i], tb[i]);
    return ifft(ta);
  }
};

const int MAX = 10010;

int f[MAX], invf[MAX];

int main(void) {
  NTT::findPrimitiveRoot();
  
  f[0] = 1;
  FOR(i, 1, MAX) f[i] = mul(f[i-1], i);
  REP(i, MAX) invf[i] = powmod(f[i], mod-2);
  
  static char a[MAX], b[MAX];
  scanf("%s", a);
  scanf("%s", b);

  int n = strlen(a);
  int x = 0, y = 0;
  REP(i, n) {
    if (a[i] == '1') {
      if (b[i] == '0') x++;
      else y++;
    }
  }

  vector<int> r(y + 1, 1);
  vector<int> v(y + 1);
  for (int i = 0; i <= y; ++i) {
    v[i] = invf[i + 1];
  }

  
  int e = x;
  while (e > 0) {
    if (e % 2) {
      r = NTT::mult(v, r);
      r.resize(y + 1);
    }
    v = NTT::mult(v, v);
    v.resize(y + 1);
    e /= 2;
  }

  int ret = r[y];
  ret = mul(ret, f[x + y]);
  ret = mul(ret, f[y]);
  ret = mul(ret, f[x]);
  printf("%d\n", ret);
  return 0;
}
