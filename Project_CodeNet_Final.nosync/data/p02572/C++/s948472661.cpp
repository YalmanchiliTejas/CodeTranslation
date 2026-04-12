#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = (n - 1); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 100000007;

const int mod = 1000000007;
struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
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
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  mint total = 0;
  rep(i, n) {
    cin >> a[i];
    total += a[i];
  }
  mint ans = 0;
  rep(i, n - 1) {
    total -= a[i];
    ans += total * a[i];
  }
  cout << ans << endl;
}