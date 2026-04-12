#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <cmath>
#include <utility> // pair make_pair
#include <algorithm>
#include <functional>
#include <iomanip>
#include <climits> // LLONG_MAX, LLONG_MIN, INT_MIN, INT_MAX
#include <assert.h>

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))
#define ll long long
#define int ll
#define INF INT_MAX/10

using namespace std;
using Pi = pair<int, int>;
using Graph = vector<vector<int> >;
using WeightGraph = vector<vector<Pi> >;

int Input[100100];


const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main() {
  // 前処理
  COMinit();

  int N, M, K; cin >> N >> M >> K;

  int ans = 0;


  int a = (M - 1) * M * (M + 1) / 6;
  a %= MOD;
  int b = (N - 1) * N * (N + 1) / 6;
  b %= MOD;


  int ms = (M * M) % MOD;
  int xs = (COM(N*M - 2, K - 2) * b) % MOD;
  ans += ms * xs;
  ans %= MOD;
  int ns = (N * N) % MOD;
  int ys = (COM(N*M - 2, K - 2) * a) % MOD;
  ans += ns * ys;
  ans %= MOD;
   
  cout << ans << endl;
}
