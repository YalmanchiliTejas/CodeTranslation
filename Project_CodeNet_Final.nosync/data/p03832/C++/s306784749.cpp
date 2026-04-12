#include <bits/stdc++.h>
using namespace std;

void solve(std::istream &in, std::ostream &out);

int main() {
#ifdef LOCAL
  freopen("../IO/e.in", "r", stdin);
//  freopen("../IO/e.out", "w", stdout);
#else
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
#endif
  solve(std::cin, std::cout);
  return 0;
}

int dp[4000][4000];
constexpr int P = 1000'000'007;
int64_t qpow(int64_t a, int64_t b) {
  a %= P;
  int64_t res = 1;
  for (; b; b >>= 1, (a *= a) %= P) if (b & 1) (res *= a) %= P;
  return res;
}
void solve(std::istream &in, std::ostream &out) {
  int n, a, b, c, d;
  in >> n >> a >> b >> c >> d;
  vector<int> fac(n + 1, 1), ifac(n + 1, 1), rev(n + 1, 0);
  rev[1] = 1;
  for (int i = 2; i <= n; ++i) {
    rev[i] = (P - (int64_t) (P / i) * rev[P % i] % P) % P;
    fac[i] = (int64_t) fac[i - 1] * i % P;
    ifac[i] = (int64_t) ifac[i - 1] * rev[i] % P;
    assert((int64_t) fac[i] * ifac[i] % P == 1);
  }
  auto choose = [&](int n, int k) -> int64_t {
    if (k > n || k < 0) return 0;
    else return (int64_t) fac[n] * ifac[k] % P * ifac[n - k] % P;
  };
  dp[a - 1][0] = 1;
  for (int i = a; i <= b; ++i) {
    for (int j = n; j >= 0; --j) {
      dp[i][j] = dp[i - 1][j];
      for (int k = c; k <= d && k * i <= j; ++k) {
        (dp[i][j] += (int64_t) dp[i - 1][j - k * i] *
                     choose(n - (j - k * i), k * i) % P * fac[k * i] %
                     P * qpow(ifac[i], k) % P * ifac[k] % P) %= P;
      }
    }
  }
  out << dp[b][n] << '\n';
}