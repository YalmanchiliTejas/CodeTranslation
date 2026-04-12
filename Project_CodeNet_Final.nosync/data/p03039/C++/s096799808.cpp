#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 202020;
const int MOD = 1e9 + 7;

int fac[MAX], finv[MAX], inv[MAX];

//前処理Ｏ(n)
void CombInit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算Ｏ(1)_nCk
int nCk(int n, int k) {
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main() {
  int N, M, K;
  cin >> N >> M >> K;

  CombInit();

  int tmp = 0;
  for (int i = 1; i <= M; i++) {
    tmp += (M - i) * i % MOD;
    tmp %= MOD;
  }
  tmp *= N * N % MOD;
  tmp %= MOD;
  tmp *= nCk(N * M - 2, K - 2);
  tmp %= MOD;

  int tmpp = 0;
  for (int i = 1; i <= N; i++) {
    tmpp += (N - i) * i % MOD;
    tmpp %= MOD;
  }
  tmpp *= M * M % MOD;
  tmpp %= MOD;
  tmpp *= nCk(N * M - 2, K - 2);
  tmpp %= MOD;

  cout << (tmp + tmpp) % MOD << endl;
  return 0;
}
