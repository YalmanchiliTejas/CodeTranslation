#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9
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

int main(){
  COMinit();
  string N;
  int K;
  cin >> N >> K;
  ll ans = 0;
  int beki = 1;
  REP(i, K-1){
    beki *= 9;
  }
  // for(int i = N.size()-1; i >= K; i--){
  //   ans += 9 * COM(i-1, K-1) * beki;
  // }
  // cerr << ans << endl;
  int cnt = 0;
  REP(i, N.size()){
    if(N[i] != '0'){
      cnt++;
      if(cnt == K){
        ans += (N[i]-'0');
        ans += COM(N.size()-i-1, 1) * 9;
        break;
      }
      else if(cnt == K-1){
        ans += (N[i]-'0'-1) * COM(N.size()-i-1, 1) * 9;
        ans += COM(N.size()-i-1, 2) * 9 * 9;
      }
      else if(cnt == K-2){
        ans += (N[0]-'0'-1) * COM(N.size()-1, K-1) * beki;
        ans += COM(N.size()-1 , K) * 9 * 9 * 9;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
