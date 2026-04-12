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
#define MAX 510000
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
ll modinv(ll a, ll m){
  ll b=m,u=1,v=0;
  while(b){
    ll t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  u%=m;
  if(u<0) u+=m;
  return u;
}
long long pow(long long a, long long n, long long m) {
    if (n == 0) return 1 % m;
    long long t = pow(a, n / 2, m);
    t = (t * t)%m;
    if (n & 1) t = (t * a)%m;
    return t;
}

#define MN 1100
  ll dp[MN][MN]={};
signed main(){
  init_io();
  COMinit();
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  dp[0][0] = 1;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=b-a+1;j++){
      ll v = a+j;
      dp[i][j+1] += dp[i][j];
      dp[i][j+1] %= MOD;
      for(int k=c;k<=d;k++){
        ll idx = i + v*k;
        if(idx > n) break;
        ll cm = COM(n-i,v*k);
        ll dv = fac[v*k] * pow(finv[v],k,MOD)%MOD;
        ll ml = ((cm * dv)%MOD * finv[k])% MOD;
        dp[idx][j+1] += (dp[i][j] * ml % MOD)%MOD;
      }
    }
  }
  cout << dp[n][b-a+1]<<endl;
}
