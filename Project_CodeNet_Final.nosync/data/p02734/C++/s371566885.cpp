#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(i64 (i) = (s);(i) < (e);(i)++)
#define all(x) x.begin(),x.end()

template<class T>
static inline std::vector<T> ndvec(size_t&& n, T val) noexcept {
  return std::vector<T>(n, std::forward<T>(val));
}

template<class... Tail>
static inline auto ndvec(size_t&& n, Tail&&... tail) noexcept {
  return std::vector<decltype(ndvec(std::forward<Tail>(tail)...))>(n, ndvec(std::forward<Tail>(tail)...));
}

template<class T, class Cond>
struct chain {
  Cond cond; chain(Cond cond) : cond(cond) {}
  bool operator()(T& a, const T& b) const {
    if(cond(a, b)) { a = b; return true; }
    return false;
  }
};
template<class T, class Cond>
chain<T, Cond> make_chain(Cond cond) { return chain<T, Cond>(cond); }


#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<i64 M>
constexpr i64 euinv(i64 val) {
    i64 a = M, b = val;
    i64 x = 0, u = 1;
    while (b) {
        i64 t = a / b;
        swap(a -= t * b, b);
        swap(x -= t * u, u);
    }
    return x < 0 ? x + M : x;
}

template<i64 M>
struct modint {
  i64 a;
  constexpr modint(const i64 x = 0) noexcept: a((x % M + M) % M) {}
  constexpr i64 value() const noexcept { return a; }
  constexpr modint inv() const noexcept { return modint(euinv<M>(a)); }
  constexpr modint pow(i64 r) const noexcept {
    modint ans(1);
    modint aa = *this;
    while(r) {
      if(r & 1) {
        ans *= aa;
      }
      aa *= aa;
      r >>= 1;
    }
    return ans;
  }
  constexpr modint& operator+=(const modint r) noexcept {
    a += r.a;
    if(a >= M) a -= M;
    return *this;
  }
  constexpr modint& operator=(const i64 r) {
    a = (r % M + M) % M;
    return *this;
  }
  constexpr modint& operator-=(const modint r) noexcept {
    a -= r.a;
    if(a < 0) a += M;
    return *this;
  }
  constexpr modint& operator*=(const modint r) noexcept {
    a = a * r.a % M;
    return *this;
  }
  constexpr modint& operator/=(modint r) noexcept {
    i64 ex = M - 2;
    while(ex) {
      if(ex & 1) {
        *this *= r;
      }
      r *= r;
      ex >>= 1;
    }
    return *this;
  }

  constexpr modint operator+(const modint r) const {
    return modint(*this) += r;
  }
  constexpr modint operator-(const modint r) const {
    return modint(*this) -= r;
  }
  constexpr modint operator*(const modint r) const {
    return modint(*this) *= r;
  }
  constexpr modint operator/(const modint r) const {
    return modint(*this) /= r;
  }

  constexpr bool operator!=(const modint r) const {
    return this->value() != r.value();
  }

};

template<const i64 M>
std::ostream& operator<<(std::ostream& os, const modint<M>& m) {
  os << m.value();
  return os;
}

int main() {
  i64 N, S;
  cin >> N >> S;
  vector<i64> A(N);
  rep(i,0,N) cin >> A[i];

  using fp = modint<998244353>;

  auto dp = ndvec(N + 1, S + 1, fp(0));
  rep(i,0,N + 1) {
    dp[i][0] = fp(1);
  }

  rep(i,0,N) {
    rep(j,0,S + 1) {
      if(j < S) {
        dp[i + 1][j] += dp[i][j];
      }
      if(j >= A[i]) {
        dp[i + 1][j] += dp[i][j - A[i]];
      }
      //cout << i + 1 << " : " << j << " = " << dp[i + 1][j] << endl;
    }
  }

  fp ans(0);
  rep(i,0,N + 1) {
    //cout << i << " = " << dp[i][S] << endl;
    ans += dp[i][S] * (N - i + 1);
  }
  cout << ans << endl;
}
