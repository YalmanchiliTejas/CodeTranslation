#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int mod = 1000000007;

struct mint {
    ll x;

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

    mint inv() const {
      return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
      return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
      mint res(*this);
      return res /= a;
    }
};

signed main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<mint> pref_sum(n + 1);
  pref_sum[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref_sum[i] += pref_sum[i - 1] + a[i];
  }

  mint ans = 0;
  mint sum = pref_sum[n - 1];
  for (int i = 0; i < n - 1; i++) {
    mint v = sum - pref_sum[i];
    mint x = a[i];
    ans += x * v;
  }

  cout << ans.x << '\n';

}
