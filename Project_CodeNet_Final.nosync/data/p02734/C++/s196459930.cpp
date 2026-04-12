#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
#define ln '\n'
//constexpr long long MOD = 1000000007LL;
constexpr long long MOD = 998244353LL;
typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true;} return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true;} return false; }
///////////////////////////////////////////////////////////////////////////////////////////////////

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
	int N,S; cin >> N >> S;
	vector<int> A(N);
	rep(i,N) cin >> A[i];

	vector<vector<mint>> dp(N+1, vector<mint>(S+1));
	rep(i,N) dp[i][0] = 1;
	mint ans = 0;
	rep(i,N) {
		rep(j,S+1) {
			dp[i+1][j] += dp[i][j];
			if (A[i] <= j) dp[i+1][j] += dp[i][j-A[i]];
			if (j==S) {
				ans += dp[i+1][j]*(N-i);
				dp[i+1][j] = 0;
			} 
		}
	}

	cout << ans.a << ln;
}
