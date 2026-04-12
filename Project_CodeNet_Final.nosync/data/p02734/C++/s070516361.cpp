#include <bits/stdc++.h>

#define rep(i, a) for (int i = 0; i < (a); ++i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)


using namespace std;
using ll = long long;
using P = pair<int, int>;
const int mod = 998244353;
// auto mod int
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
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

void Main() {
  int n, s;
  cin >> n >> s;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  mint ans = 0;
  vector<mint> q(s+1);
  rep(i, n) {
    q[0] += 1;
    vector<mint> q2(s+1);
    rep(j, s+1) {
      q2[j] += q[j];
      if (j+A[i] <= s) q2[j+A[i]] += q[j];
    }
    q = q2;
    ans += q[s];
  }
  cout << ans << endl;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  Main();
  return 0;
}

