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


#include <vector>
using i64 = long long;

template<class T>
void build_factorial(std::vector<T>& fact, std::vector<T>& finv, std::vector<T>& inv) {
  std::size_t N = fact.size();
  fact[0] = T(1);
  for(int i = 1;i < N;i++) {
    fact[i] = fact[i - 1] * T(i);
  }
  finv[N - 1] = T(1) / fact[N - 1];
  for(int i = N - 1; i --> 0;) {
    finv[i] = finv[i + 1] * T(i + 1);
  }
  for(int i = 0;i < N;i++) {
    inv[i] = fact[i - 1] * finv[i];
  }
}

int main() {
  i64 N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  using fp = modint<(i64)(1e9 + 7)>;
  vector<vector<fp>> dp(N + 1, vector<fp>(N + 1, fp(0)));

  vector<fp> fact(N + 1);
  vector<fp> finv(N + 1);
  vector<fp> inv(N + 1);
  build_factorial(fact, finv, inv);

  dp[A - 1][0] = fp(1);

  rep(i,A, B + 1) {
    rep(j,0,N + 1){
      dp[i][j] += dp[i - 1][j];

      fp ifact = finv[i].pow(C);
      rep(k,C,D + 1) {
        if(j >= i * k) {
          dp[i][j] += dp[i - 1][j - i * k] * fact[N - j + i * k] * finv[N - j] * ifact * finv[k];
          ifact *= finv[i];
        }
        else {
          break;
        }
      }
    }
  }
  cout << dp[B][N] << endl;
}
