#include <bits/stdc++.h>

using namespace std;
using ll = long long;
namespace mod {

template <class t, int m>
class mint;

template <class t, int m>
mint<t, m> pow(const mint<t, m> &base, t exp);

template <class t, int m>
mint<t, m> inv(const mint<t, m> &n);

template <class t, int m>
class mint {
  t n_;

 public:
  mint() : n_(0) {}
  mint(t n) : n_((n % m + m) % m) {}

  mint &operator+=(const mint &rhs) {
    n_ += rhs.n_;
    if (n_ >= m) {
      n_ -= m;
    }

    return *this;
  }

  mint &operator-=(const mint &rhs) {
    n_ += m - rhs.n_;
    if (n_ >= m) {
      n_ -= m;
    }

    return *this;
  }

  mint &operator*=(const mint &rhs) {
    n_ = n_ * rhs.n_ % m;
    return *this;
  }

  mint &operator/=(const mint &rhs) { return (*this) *= inv(rhs); }

  t get() { return n_; }
};

template <class t, int m>
mint<t, m> operator-(const mint<t, m> &lhs, const mint<t, m> &rhs) {
  mint<t, m> res(lhs);
  return res -= rhs;
}

template <class t, int m>
mint<t, m> operator+(const mint<t, m> &lhs, const mint<t, m> &rhs) {
  mint<t, m> res(lhs);
  return res += rhs;
}

template <class t, int m>
mint<t, m> operator*(const mint<t, m> &lhs, const mint<t, m> &rhs) {
  mint<t, m> res(lhs);
  return res *= rhs;
}

template <class t, int m>
mint<t, m> operator/(const mint<t, m> &lhs, const mint<t, m> &rhs) {
  mint<t, m> res(lhs);
  return res /= rhs;
}

template <class t, int m>
mint<t, m> pow(const mint<t, m> &base, t exp) {
  if (exp == 0) {
    return 1;
  }

  auto a = pow(base, exp / 2);
  a *= a;
  if (exp % 2 == 1) {
    a *= base;
  }

  return a;
}

template <class t, int m>
mint<t, m> inv(const mint<t, m> &n) {
  return pow(n, static_cast<t>(m - 2));
}
}  // namespace mod

const int md = 1e9 + 7;
using mint = mod::mint<long long, md>;

int main(int argc, const char *argv[]) {
  //
  int n;
  cin >> n;

  vector<mint> va;
  mint sum = 0;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    va.emplace_back(a);
    sum += va.back();
  }

  vector<mint> psum{0};
  partial_sum(va.begin(), va.end(), back_inserter(psum));

  mint ans = 0;
  for (int i = 0; i < n; ++i) {
    mint a = va[i];
    ans += (psum.back() - psum[i + 1]) * a;
  }

  cout << ans.get() << '\n';
  return 0;
}