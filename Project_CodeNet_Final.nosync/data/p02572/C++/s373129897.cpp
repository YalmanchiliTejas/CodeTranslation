#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-12;
static const double PI = acos(-1.0);

template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const {
    return mint(-x);
  }
  mint &operator+=(const mint a) {
    if ((x += a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator-=(const mint a) {
    if ((x += mod - a.x) >= mod)
      x -= mod;
    return *this;
  }
  mint &operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    return mint(*this) += a;
  }
  mint operator-(const mint a) const {
    return mint(*this) -= a;
  }
  mint operator*(const mint a) const {
    return mint(*this) *= a;
  }
  mint pow(ll t) const {
    if (!t)
      return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1)
      a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod - 2);
  }
  mint &operator/=(const mint a) {
    return *this *= a.inv();
  }
  mint operator/(const mint a) const {
    return mint(*this) /= a;
  }
};
istream &operator>>(istream &is, const mint &a) {
  return is >> a.x;
}
ostream &operator<<(ostream &os, const mint &a) {
  return os << a.x;
}

void solve(long long N, std::vector<long long> A) {
  mint sum = 0;
  REP(i, N) {
    sum += A[i];
  }
  mint ans = 0;
  REP(i, N - 1) {
    sum -= A[i];
    ans += mint(A[i]) * sum;
  }
  cout << ans << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }
  solve(N, std::move(A));
  return 0;
}
