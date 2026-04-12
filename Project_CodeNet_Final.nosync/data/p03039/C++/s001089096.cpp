#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MOD = 1000000007;
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void initComb() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
long long comb(int n, int r) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

int main(){
  initComb();
  ll N, M, K;
  cin >> N >> M >> K;
  int sum = 0;
  rep(i, N)
    sum = (sum+i*(N-i)*M%MOD*M%MOD)%MOD; //2点間の縦方向の距離がiになる組合せの和(他の点は無視)
  rep(i, M)
    sum = (sum+i*(M-i)*N%MOD*N%MOD)%MOD; //2点間の横方向の距離がiになる組合せの和(他の点は無視)
  ll ans = sum*comb(N*M-2, K-2); //2点を固定する組合せは、他の点のパターン分存在する
  ans %= MOD;
  cout << ans << endl;
}