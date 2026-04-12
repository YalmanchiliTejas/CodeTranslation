#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
const double PI = acos(-1);
const ll MOD = 1000000007;
// const ll MOD = 998244353;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

using mint = modint<MOD>;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string K; cin >> K;
    int D; cin >> D;
    int N = K.size();

    vector<vector<vector<mint>>> dp(N+1, vector<vector<mint>>(2, vector<mint>(D)));

    dp[0][0][0] = 1;
    rep(i,N) {
        rep(j,D) {
            rep(k,10) {
                dp[i+1][1][(j+k)%D] += dp[i][1][j];
                if (k <= K[i] - '0') {
                    if (k == K[i] - '0') {
                        dp[i+1][0][(j+k)%D] += dp[i][0][j];
                    } else dp[i+1][1][(j+k)%D] += dp[i][0][j];
                }
            }
        }
    }

    cout << (dp[N][0][0] + dp[N][1][0] - 1).a << endl;
}