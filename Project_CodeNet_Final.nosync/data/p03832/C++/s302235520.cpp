#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const ll mod=1e9+7;
ll mu(ll a,ll b){
  return (ll)a*b%mod;
}
ll ad(ll a,ll b){
  if((a+=b)>=mod)a%=mod;
  return a;
}
ll pw(ll a,ll b,ll c=1LL){
  for(;b;b>>=1,a=mu(a,a))if(b&1)c=mu(c,a);
  return c;
}
ll dv(ll a,ll b){
  return mu(a,pw(b,mod-2));
}
ll fac2[1001][1001];
ll dp[1001][1001];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;

  ll fac[n+1];
  fac[0] = 1;
  rep(i,n) fac[i+1] = mu(fac[i],i+1);
  ll inv[n+1];
  rep(i,n+1) inv[i] = dv(1,fac[i]);

  rep(i,n+1)rep(j,n+1) if(i>=j) fac2[i][j] = dv(fac[i],fac[j]);

  rep(i,n+1)rep(j,n+1) dp[i][j] = 0;
  dp[0][0] = 1;
  rep1(i,n){
    rep(j,n+1){
      dp[i][j] = dp[i-1][j];
    }
    if(i<a || b<i) continue;
    rep(j,n+1){
      for(int l = c; l<=d; l++){
        if(j-i*l<0) break;
        ll k = n - (j-i*l);
        // cout << "tot hito kumi res " << k << " " <<  i <<" " << l << " " << endl;
        ll coef = mu(mu(inv[l],pw(inv[i],l)),fac2[k][k-i*l]);
        dp[i][j] = ad(dp[i][j],mu(coef,dp[i-1][j-i*l]));
      }
    }
  }
  cout << dp[n][n] << endl;
  // cout << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s"<<endl;
  
  return 0;
    

}
