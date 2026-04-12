#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
#define vall(x) (x).begin(), (x).end()
using namespace std;
using lli = long long int;
void YESNO(bool), YesNo(bool);
template <class T1, class T2> bool chmin(T1 &l, const T2 &r);
template <class T1, class T2> bool chmax(T1 &l, const T2 &r);
template <class T1, class T2> void vadd(vector<T1> &v, T2 x);

const int MF = 100005, MOD = 1000000007;

template <signed M, unsigned T> struct mod_int {
  constexpr static signed MODULO = M;
  constexpr static unsigned TABLE_SIZE = T;

  signed x;

  mod_int() : x(0) {}

  mod_int(long long y)
      : x(static_cast<signed>(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO)) {}

  mod_int(int y) : x(y >= 0 ? y % MODULO : MODULO - (-y) % MODULO) {}

  mod_int &operator+=(const mod_int &rhs) {
    if ((x += rhs.x) >= MODULO)
      x -= MODULO;
    return *this;
  }

  mod_int &operator-=(const mod_int &rhs) {
    if ((x += MODULO - rhs.x) >= MODULO)
      x -= MODULO;
    return *this;
  }

  mod_int &operator*=(const mod_int &rhs) {
    x = static_cast<signed>(1LL * x * rhs.x % MODULO);
    return *this;
  }

  mod_int &operator/=(const mod_int &rhs) {
    x = static_cast<signed>((1LL * x * rhs.inv().x) % MODULO);
    return *this;
  }

  mod_int operator-() const { return mod_int(-x); }

  mod_int operator+(const mod_int &rhs) const { return mod_int(*this) += rhs; }

  mod_int operator-(const mod_int &rhs) const { return mod_int(*this) -= rhs; }

  mod_int operator*(const mod_int &rhs) const { return mod_int(*this) *= rhs; }

  mod_int operator/(const mod_int &rhs) const { return mod_int(*this) /= rhs; }

  bool operator<(const mod_int &rhs) const { return x < rhs.x; }

  mod_int inv() const {
    assert(x != 0);
    if (x <= static_cast<signed>(TABLE_SIZE)) {
      if (_inv[1].x == 0)
        prepare();
      return _inv[x];
    } else {
      signed a = x, b = MODULO, u = 1, v = 0, t;
      while (b) {
        t = a / b;
        a -= t * b;
        std::swap(a, b);
        u -= t * v;
        std::swap(u, v);
      }
      return mod_int(u);
    }
  }

  mod_int pow(long long t) const {
    assert(!(x == 0 && t == 0));
    mod_int e = *this, res = mod_int(1);
    for (; t; e *= e, t >>= 1)
      if (t & 1)
        res *= e;
    return res;
  }

  mod_int fact() {
    if (_fact[0].x == 0)
      prepare();
    return _fact[x];
  }

  mod_int inv_fact() {
    if (_fact[0].x == 0)
      prepare();
    return _inv_fact[x];
  }

  mod_int choose(mod_int y) {
    assert(y.x <= x);
    return this->fact() * y.inv_fact() * mod_int(x - y.x).inv_fact();
  }

  static mod_int _inv[TABLE_SIZE + 1];

  static mod_int _fact[TABLE_SIZE + 1];

  static mod_int _inv_fact[TABLE_SIZE + 1];

  static void prepare() {
    _inv[1] = 1;
    for (int i = 2; i <= (int)TABLE_SIZE; ++i) {
      _inv[i] = 1LL * _inv[MODULO % i].x * (MODULO - MODULO / i) % MODULO;
    }
    _fact[0] = 1;
    for (unsigned i = 1; i <= TABLE_SIZE; ++i) {
      _fact[i] = _fact[i - 1] * int(i);
    }
    _inv_fact[TABLE_SIZE] = _fact[TABLE_SIZE].inv();
    for (int i = (int)TABLE_SIZE - 1; i >= 0; --i) {
      _inv_fact[i] = _inv_fact[i + 1] * (i + 1);
    }
  }
};

template <int M, unsigned F>
std::ostream &operator<<(std::ostream &os, const mod_int<M, F> &rhs) {
  return os << rhs.x;
}

template <int M, unsigned F>
std::istream &operator>>(std::istream &is, mod_int<M, F> &rhs) {
  long long s;
  is >> s;
  rhs = mod_int<M, F>(s);
  return is;
}

template <int M, unsigned F> mod_int<M, F> mod_int<M, F>::_inv[TABLE_SIZE + 1];

template <int M, unsigned F> mod_int<M, F> mod_int<M, F>::_fact[TABLE_SIZE + 1];

template <int M, unsigned F>
mod_int<M, F> mod_int<M, F>::_inv_fact[TABLE_SIZE + 1];

template <int M, unsigned F>
bool operator==(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
  return lhs.x == rhs.x;
}

template <int M, unsigned F>
bool operator!=(const mod_int<M, F> &lhs, const mod_int<M, F> &rhs) {
  return !(lhs == rhs);
}

using mint = mod_int<MOD, MF>;
mint binom(int n, int r) {
  return (r < 0 || r > n || n < 0) ? 0 : mint(n).choose(r);
}

mint fact(int n) { return mint(n).fact(); }

mint inv_fact(int n) { return mint(n).inv_fact(); }

void solve(long long N, std::vector<long long> A) {
  mint sum = 0, nijo = 0;
  for (auto s : A) {
    sum += mint(s);
    nijo += mint(s) * mint(s);
  }
  cout << (sum * sum -  nijo) / mint(2) << endl;
}

signed main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2> bool chmin(T1 &l, const T2 &r) {
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2> bool chmax(T1 &l, const T2 &r) {
  return (l < r) ? (l = r, true) : false;
}

template <class T1, class T2> void vadd(vector<T1> &v, T2 x) {
  for (auto &s : v)
    s += T2(x);
}
