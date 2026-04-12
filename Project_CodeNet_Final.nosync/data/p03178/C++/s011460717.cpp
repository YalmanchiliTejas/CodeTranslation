#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for (int i = 0; i < (int)N; ++i)
#define all(a) (a).begin(), (a).end()
template <int MOD>
class ModInt {
  long long x;

 public:
  ModInt(long long v = 0) : x(v % MOD) {
    if (x < 0) x += MOD;
  }

  ModInt& operator+=(const ModInt& r) {
    x += r.x;
    if (x >= MOD) x -= MOD;
    return *this;
  }

  ModInt& operator-=(const ModInt& r) {
    x -= r.x;
    if (x < 0) x += MOD;
    return *this;
  }
  ModInt& operator*=(const ModInt& r) {
    x = (x * r.x) % MOD;
    return *this;
  }
  ModInt& operator/=(const ModInt& r) {
    *this *= r.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt& r) const { return ModInt(*this) += r; }
  ModInt operator-(const ModInt& r) const { return ModInt(*this) -= r; }
  ModInt operator*(const ModInt& r) const { return ModInt(*this) *= r; }
  ModInt operator/(const ModInt& r) const { return ModInt(*this) /= r; }
  bool operator==(const ModInt& r) const { return x == r.x; }
  bool operator!=(const ModInt& r) const { return x != r.x; }

  ModInt inverse() const {
    long long a = x, b = MOD, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt<MOD> pow(long long n) const {
    ModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream& operator<<(ostream& os, const ModInt& x) { return os << x.x; }

  friend istream& operator>>(istream& is, ModInt& x) { return is >> x.x; }

  int getMod() { return MOD; }
};

using mint = ModInt<1000000007>;

string K;
int D;

int main() {
  cin >> K >> D;
  int N = K.size();

  vector<vector<vector<mint>>> dp(N + 1,
                                  vector<vector<mint>>(D, vector<mint>(2, 0)));
  dp[0][0][1] = 1;

  rep(i, N) {
    int m = K[i] - '0';
    rep(j, D) {
      dp[i + 1][j][1] = dp[i][(j - m + 10 * D) % D][1];
      rep(l, 10) {
        dp[i + 1][j][0] += dp[i][(j - l + 10 * D) % D][0];
        if (l < m) dp[i + 1][j][0] += dp[i][(j - l + 10 * D) % D][1];
      }
    }
  }

  cout << dp[N][0][0] + dp[N][0][1] - 1 << endl;

  return 0;
}
