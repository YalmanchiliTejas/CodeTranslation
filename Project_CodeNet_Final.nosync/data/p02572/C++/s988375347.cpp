#include <algorithm>
#include <bitset>
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

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

#include <cstdint>

using std::int64_t;

template <int64_t MOD>
class Modint {
  using Self = Modint<MOD>;

  int64_t m_value;

 public:
  Modint() : m_value(0) {}
  Modint(int64_t value) : m_value((value % MOD + MOD) % MOD) {}
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
  Self& operator/=(const Self& rh) { return (*this) = (*this) / rh; }
  int64_t value() const { return m_value; }
};

int main() {
  int N;
  cin >> N;

  vector<int64_t> a(N);
  for (auto& elm : a) {
    cin >> elm;
  }

  using Mint = Modint<1'000'000'007>;
  vector<Mint> b(N + 1);
  b[0] = 0;
  rep(i, N) { b[i + 1] = b[i] + a[i]; }

  Mint result = 0;
  rep(i, N) { result += b[i] * a[i]; }
  cout << result.value() << endl;

  return 0;
}