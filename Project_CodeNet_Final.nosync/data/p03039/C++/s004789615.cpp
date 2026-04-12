#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(i=0;i<N;i++)
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL; 
  typedef pair<ll,char> PLC; 
  typedef pair<char,ll> PCL; 

const int MAX = 510000;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

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
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(void){
  ll N,M,K;cin >> N >> M >> K;
  COMinit();

  ll N_ = 0, M_ = 0;
  int i;
  REP(i,N-1){
    N_ += ((i+1)*(N-1-i))%MOD;
    N_ %= MOD;
  }

  REP(i,M-1){
    M_ += ((i+1)*(M-1-i))%MOD;
    M_ %= MOD;
  }

  ll combi = COM(N*M-2,K-2)%MOD;
  
  ll r1 = 0, r2 = 0, ans = 0;
  r1 = (combi*M_)%MOD;
  r1 *= N;
  r1 %= MOD;
  r1 *= N;
  r1 %= MOD;

  r2 = (combi*N_)%MOD;
  r2 *= M;
  r2 %= MOD;
  r2 *= M;
  r2 %= MOD;

  ans = (r1+r2)%MOD;
  cout << ans << endl;
  return 0;
}
