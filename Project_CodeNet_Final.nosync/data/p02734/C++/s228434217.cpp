#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

template<int Mod> class ModInt {
  int v;
public:
  constexpr ModInt(const long long x = 0) noexcept : v((x % Mod + Mod) % Mod) {};
  constexpr ModInt &operator+=(const ModInt rhs) noexcept {
    v += rhs.v;
    if (v >= Mod)
      v -= Mod;
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt rhs) noexcept {
    if (v < rhs.v)
      v += Mod;
    v -= rhs.v;
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt rhs) noexcept {
    v = int(1LL * v * rhs.v % Mod);
    return *this;
  }
  constexpr ModInt &operator/=(ModInt rhs) noexcept {
    long long exp = Mod - 2;
    while (exp) {
      if (exp & 1)
        *this *= rhs;
      rhs *= rhs;
      exp >>= 1;
    }
    return *this;
  }
  constexpr ModInt operator-() const noexcept { return ModInt(-v); }
  constexpr ModInt operator+(const ModInt rhs) const noexcept {
    return ModInt(*this) += rhs;
  }
  constexpr ModInt operator-(const ModInt rhs) const noexcept {
    return ModInt(*this) -= rhs;
  }
  constexpr ModInt operator*(const ModInt rhs) const noexcept {
    return ModInt(*this) *= rhs;
  }
  constexpr ModInt operator/(const ModInt rhs) const noexcept {
    return ModInt(*this) /= rhs;
  }
  constexpr bool operator==(const ModInt rhs) const noexcept {
    return v == rhs.v;
  }
  constexpr bool operator!=(const ModInt rhs) const noexcept {
    return v != rhs.v;
  }
  constexpr ModInt pow(long long exp) const noexcept {
    ModInt res(1), mul(v);
    while (exp) {
      if (exp & 1)
        res *= mul;
      mul *= mul;
      exp >>= 1;
    }
    return res;
  }
  friend ostream &operator<<(ostream &os, const ModInt obj) noexcept {
    return os << obj.v;
  }
  friend istream &operator>>(istream &is, ModInt &obj) noexcept {
    long long tmp;
    is >> tmp;
    obj = ModInt<Mod>(tmp);
    return is;
  }
};
constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<vector<mint>> dp(n+1, vector<mint>(s+1));
  mint ans = 0;
  for (int i = n-1; i >= 0; i--) {
    if (s-a[i] > 0)
      ans += dp[i+1][s-a[i]]*(i+1);
    else if (s-a[i] == 0)
      ans += (i+1)*(n-i);
    rep(j, s)
      dp[i][j] = dp[i+1][j];
    for (int j = s-1; j > 0; j--) {
      if (j+a[i] <= s)
        dp[i][j+a[i]] += dp[i+1][j];
    }
    if (a[i] <= s)
      dp[i][a[i]] += n-i;
  }
  cout << ans << endl;
  return 0;
}