#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

const long long MAX = 510000;  // 最大を決めておく
// fac…階乗、inv…逆数、finv…逆数の累積積
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理、先にやっておく
void nCr_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// nCrを計算する (前処理は忘れないように)
long long nCr(int n, int r) {
  if (n < r) return 0;
  if (n < 0 || r < 0) return 0;
  return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

// ====================================================================

int main() {
  nCr_init();

  ll h, w, k;
  cin >> h >> w >> k;

  ll ans = 0;
  for (ll dx = 1; dx < w; dx++) {  // その横幅を、全探索。
    ans = (dx * (w - dx) * h % MOD * h % MOD * nCr(h * w - 2, k - 2) % MOD + ans) % MOD;
  }
  for (ll dy = 1; dy < h; dy++) {  // その横幅を、全探索。
    ans = (dy * (h - dy) * w % MOD * w % MOD * nCr(h * w - 2, k - 2) % MOD + ans) % MOD;
  }

  cout << ans << endl;
}
