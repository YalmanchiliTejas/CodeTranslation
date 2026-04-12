#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

template <int64_t MOD>
class Modint {
  using Self = Modint<MOD>;

  int64_t m_value;

 public:
  explicit Modint(int64_t value) : m_value((value % MOD + MOD) % MOD) {}
  Self pow(int64_t e) const {
    if (e == 0) {
      return (Self)1;
    } else if (e % 2 == 0) {
      return ((*this) * (*this)).pow(e / 2);
    } else {
      return (*this).pow(e - 1) * (*this);
    }
  }
  Self inv() const { return pow(MOD - 2); }
  Self& operator=(const Self& rh) {
    m_value = rh.m_value;
    return *this;
  }
  Self operator-() const { return Self(-m_value); }
  Self operator+(const Self& other) const {
    return Self(m_value + other.m_value);
  }
  Self operator-(const Self& other) const {
    return Self(m_value - other.m_value);
  }
  Self operator*(const Self& other) const {
    return Self(m_value * other.m_value);
  }
  Self operator/(const Self& other) const { return (*this) * other.inv(); }
  Self& operator+=(const Self& rh) { return (*this) = (*this) + rh; }
  Self& operator-=(const Self& rh) { return (*this) = (*this) - rh; }
  Self& operator*=(const Self& rh) { return (*this) = (*this) * rh; }
  int64_t value() const { return m_value; }
};

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> a(N);
  rep(i, N) { cin >> a[i]; }

  using Mint = Modint<998244353>;
  vector<vector<Mint>> dp(N + 1, vector<Mint>(S + 1, (Mint)0));

  rep(i, N) irep(j, S) {
    dp[i + 1][j] = dp[i][j];
    if (j - a[i] == 0) {
      dp[i + 1][j] += Mint(i + 1);
    } else if (j - a[i] > 0) {
      dp[i + 1][j] += dp[i][j - a[i]];
    }
  }

  Mint result = (Mint)0;
  rep(i, N) { result += (dp[i + 1][S] - dp[i][S]) * Mint(N - i); }
  cout << result.value() << endl;

  return 0;
}