//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
#define int long long
   template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
    const int MAX =1002;
const int MOD =1000000007;
int fac[MAX], finv[MAX], inv[MAX];

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
int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
signed main(){
  COMinit();
  int n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  int ans[n+1]={};
  ans[n]=1;
  for(int i=a;i<=b;i++){
    for(int j=0;j<n;j++){
      int t=1;
      for(int k=1;k<=d&&j+i*k<=n;k++){
        t=(t*COM(j+i*k,i))%MOD;
        if(k>=c)ans[j]=(ans[j]+t*ans[j+i*k]%MOD*finv[k]%MOD)%MOD;
      }
    }
  }
  cout<<ans[0]<<endl;
}