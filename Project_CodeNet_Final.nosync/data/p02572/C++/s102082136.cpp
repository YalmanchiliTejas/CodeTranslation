#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

const int mod = 1'000'000'007;


struct mint {
  ll x; // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}

  mint operator-() const { return mint(-x); }

  mint &operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }

  mint &operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }

  mint &operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }

  mint operator+(const mint a) const { return mint(*this) += a; }

  mint operator-(const mint a) const { return mint(*this) -= a; }

  mint operator*(const mint a) const { return mint(*this) *= a; }

  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }

  mint &operator/=(const mint a) { return *this *= a.inv(); }

  mint operator/(const mint a) const { return mint(*this) /= a; }
};

istream &operator>>(istream &is, mint &a) { return is >> a.x; }

ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  mint aSum;
  rep(i, n) {
    aSum += a.at(i);
  }
  mint aSum2 = aSum * aSum;
  mint bSum;
  rep(i, n) {
    bSum += a.at(i) * a.at(i) % mod;
  }
  mint res = (aSum2 - bSum) / 2;
  cout << res.x << endl;
  return 0;
}
