// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
#define MAX 5100000
#define MOD 1000000007

ll fac[MAX], finv[MAX], inv[MAX];

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

long long COM(int n, int k){
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
signed main(){
  init_io();
  ll n,m,k,ans=0;
  cin >> n >> m >> k;
  COMinit();
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      ll tmp = n-i;
      tmp *= ((m-j)*(i+j))%MOD;
      tmp %= MOD;
      if(i!=0&&j!=0) tmp *= 2;
      tmp %= MOD;
      ans += tmp;
      ans %= MOD;
    }
  }
  ans *= COM(n*m-2,k-2);
  ans %= MOD;
  cout << ans << endl;
}
