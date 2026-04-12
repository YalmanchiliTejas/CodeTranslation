#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

template <int M, bool IsPrime = false> class Modulo {
  int n;
  static typename std::enable_if<IsPrime, LL>::type inv(LL a, LL p) {
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
  }

public:
  Modulo() : n(0) { ; }
  Modulo(int m) : n(m) {
    if (n >= M)
      n %= M;
    else if (n < 0)
      n = (n % M + M) % M;
  }
  Modulo(LL m) {
    if (m >= M)
      m %= M;
    else if (m < 0)
      m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator LL() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo &operator+=(const Modulo &a) {
    n += a.n;
    if (n >= M) n -= M;
    return *this;
  }
  Modulo &operator-=(const Modulo &a) {
    n -= a.n;
    if (n < 0) n += M;
    return *this;
  }
  Modulo &operator*=(const Modulo &a) {
    n = (LL(n) * a.n) % M;
    return *this;
  }
  Modulo operator+(const Modulo &a) const {
    Modulo res = *this;
    return res += a;
  }
  Modulo operator-(const Modulo &a) const {
    Modulo res = *this;
    return res -= a;
  }
  Modulo operator-() const { return Modulo(0) - *this; }
  Modulo operator*(const Modulo &a) const {
    Modulo res = *this;
    return res *= a;
  }
  Modulo operator^(int m) const {
    if (m == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (m / 2);
    return m % 2 ? res * a : res;
  }
  typename std::enable_if<IsPrime, Modulo>::type
  operator/(const Modulo &a) const {
    return *this * inv(LL(a), M);
  }
  typename std::enable_if<IsPrime, Modulo>::type operator/=(const Modulo &a) {
    return *this *= inv(LL(a), M);
  }
};

template <int M, bool IsPrime = false> bool is_zero(Modulo<M, IsPrime> x) {
  return int(x) == 0;
}
template <int M, bool IsPrime = false> int abs(Modulo<M, IsPrime> x) {
  return int(x);
}

const int mod = 1000000007;

using Mod = Modulo<mod, true>;

int l, c, d;

Mod fmemo[1024] = {};
Mod fact(int n) {
  if(LL(fmemo[n])) return fmemo[n];
  else if(n == 0) return fmemo[n] = Mod(1);
  else return fmemo[n] = fact(n-1) * n;
}

Mod inv_memo[1024] = {};
Mod inv_fact(int n) {
  if(LL(inv_memo[n])) return inv_memo[n];
  else return inv_memo[n] = Mod(1) / fact(n);
}

bool mexist[1024][1024];
Mod memo[1024][1024];
Mod pattern(int n, int r) {
  if(l == r) return (n == 0 ? 1 : 0);
  if(mexist[n][r]) return memo[n][r];
  Mod answer = pattern(n, r - 1);
  FOR(g, c, d) {
    if(n < g * r) break;
    answer += pattern(n - g * r, r - 1) * inv_fact(g) * (inv_fact(r) ^ g);
  }
  mexist[n][r] = true;
  return memo[n][r] = answer;
}
int main(void)
{
  int n, r;
  cin >> n >> l >> r >> c >> d;
  --l; ++d;
  cout << LL(pattern(n, r) * fact(n)) << endl;
  return 0;
}
