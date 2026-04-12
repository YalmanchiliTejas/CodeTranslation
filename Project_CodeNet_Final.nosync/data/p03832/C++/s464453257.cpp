#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1e3+10;
const int MAXX = 1e5;
const ll MOD = 1e9+7;

ll dp[MAX][MAX];
int N, A, B, C, D;

ll fac[MAXX];  /// fac[n] = n!
ll finv[MAXX]; /// (fac[n] * finv[n]) % MOD = 1
ll inv[MAXX];  /// (n * inv[n]) % MOD = 1

void init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAXX; i++) {
    fac[i] = fac[i-1]*i % MOD;
    inv[i] = MOD - inv[MOD%i]*(MOD/i) % MOD;
    finv[i] = finv[i-1]*inv[i] % MOD;
  }
}

ll nCk (int n, int k) {
  if (n < k || k < 0 || n < 0) return 0;
  return fac[n]*finv[k]%MOD*finv[n-k]%MOD;
}

ll pow(ll x, int n) {
  ll ret = 1;
  while (n) {
    if (n&1) (ret *= x) %= MOD;
    (x *= x) %= MOD;
    n >>= 1;
  }
  return ret;
}

int main() {

  init();
  cin >> N >> A >> B >> C >> D;

  dp[A][0] = 1;
  for (int i = A*C; i <= min(N, A*D); i += A) dp[A][i] = nCk(N, i) * fac[i] % MOD * pow(finv[A], i/A) % MOD * finv[i/A] % MOD;
  
  for (int i = A+1; i <= B; i++) {
    for (int j = 0; j <= N; j++) {
      dp[i][j] = dp[i-1][j]; // i人のグループを使わない時
      for (int k = C; k <= D; k++) {
        if (j-k*i < 0) break;
        (dp[i][j] += dp[i-1][j-k*i] 
            * nCk(N-(j-k*i), k*i) % MOD // 残りのN-(j-k*i)人のうちk*i人を選出する。
            * fac[k*i] % MOD // そのk*i人を順番に並べる
            * pow(finv[i], k) % MOD // i人ずつ、k人のグループごとにする。
            * finv[k]) %= MOD; // グループの順番は関係ない
      }
    }
  }

  cout << dp[B][N] << endl;
}