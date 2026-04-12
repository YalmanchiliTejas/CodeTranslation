#include <bits/stdc++.h>
using namespace std;

template <class T, class F = multiplies<T>>
T power(T a, long long n, F op = multiplies<T>(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  unsigned v;
  modular(long long a = 0) : v((a %= M) < 0 ? a + M : a) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m r) { if ((v += r.v) >= M) v -= M; return *this; }
  m& operator-=(m r) { if (v < r.v) v += M; v -= r.v; return *this; }
  m& operator*=(m r) { v = (uint64_t)v * r.v % M; return *this; }
  m& operator/=(m r) { return *this *= power(r, M - 2); }
  friend m operator+(m l, m r) { return l += r; }
  friend m operator-(m l, m r) { return l -= r; }
  friend m operator*(m l, m r) { return l *= r; }
  friend m operator/(m l, m r) { return l /= r; }
  friend bool operator==(m l, m r) { return l.v == r.v; }
  friend string to_string(m a) { return to_string(a.v); }
};

constexpr long long mod = 998244353;
using mint = modular<mod>;

vector<mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = power(fact[n], mod - 2);
  for (int i = n; i; --i) inv_fact[i - 1] = i * inv_fact[i];
  for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}
mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template<> mint& mint::operator/=(mint r) {
  return *this *= r.v < minv.size() ? minv[r.v] : power(r, mod - 2);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  prepare(n);
  mint res = 0, sum = 0;
  for (int j = 0; j <= n / 2; ++j) {
    sum += binom(n, j);
  }
  for (int i = 0; i <= n / 2; ++i) {
    res += binom(n, i) * sum;
    sum = (sum + binom(n - i - 1, n / 2)) * minv[2];
  }
  cout << res.v << '\n';
}
