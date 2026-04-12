#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
class ModInt {
  static int MOD;
  long long x;

 public:
  static void mod(int m) { MOD = m; }

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

  ModInt pow(long long n) const {
    if (n < 0) return pow(-n).inverse();

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

  long long val() { return x; }
};
int ModInt::MOD = 1000000007;

int main() {
  ModInt::mod(998244353);

  int N, S;
  cin >> N >> S;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  enum State {
    PENDING,
    OPEN,
    CLOSED,
  };
  vector<vector<vector<ModInt>>> dp(
      N + 1, vector<vector<ModInt>>(S + 1, vector<ModInt>(3, 0)));
  dp[0][0][PENDING] = 1;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < S + 1; ++j) {
      dp[i + 1][j][CLOSED] += dp[i][j][CLOSED];

      // i not in X
      dp[i + 1][j][OPEN] += dp[i][j][OPEN];
      dp[i + 1][j][CLOSED] += dp[i][j][OPEN];
      // i in X
      if (j - A[i] >= 0) {
        dp[i + 1][j][OPEN] += dp[i][j - A[i]][OPEN];
        dp[i + 1][j][CLOSED] += dp[i][j - A[i]][OPEN];
      }

      // i not in X
      dp[i + 1][j][PENDING] += dp[i][j][PENDING];
      dp[i + 1][j][OPEN] += dp[i][j][PENDING];
      // i in X
      if (j - A[i] >= 0) {
        dp[i + 1][j][OPEN] += dp[i][j - A[i]][PENDING];
        dp[i + 1][j][CLOSED] += dp[i][j - A[i]][PENDING];
      }
    }
  }

  cout << dp[N][S][CLOSED] << endl;
  return 0;
}
