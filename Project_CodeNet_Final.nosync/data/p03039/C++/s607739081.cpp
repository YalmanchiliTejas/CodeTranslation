#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define irep(i, a, n) for (int i = a; i < (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define rrep1(i, n) for (int i = (int)(n); i >= 1; --i)
#define allrep(V, v) for (auto &&V : v)
#define all(x) (x).begin(), (x).end()
using lint = long long;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
using namespace std;

class CombinationMod {
  int mod;
  std::vector<long long> fac, finv, inv;

  public:
  CombinationMod(int max_size, int prime_mod) : fac(std::vector<long long>(max_size)), finv(std::vector<long long>(max_size)), inv(std::vector<long long>(max_size)), mod(prime_mod) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < max_size; i++) {
      fac[i] = fac[i - 1] * i % mod;
      inv[i] = mod - inv[mod % i] * (mod / i) % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
  }
  long long comb(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
  }
};

int main(void) {
  lint n, m, k;
  cin >> n >> m >> k;
  CombinationMod cm(n * m, MOD);
  lint times = cm.comb(m * n - 2, k - 2);
  lint sumx = 0, sumy = 0;
  rep1(i, m - 1) {
    sumx += i * (m - i);
  }
  sumx = (sumx % MOD) * n * n % MOD;
  rep1(i, n - 1) {
    sumy += i * (n - i);
  }
  sumy = (sumy % MOD) * m * m % MOD;
  lint sum = (sumx + sumy) % MOD * times % MOD;
  cout << sum << endl;
  return 0;
}