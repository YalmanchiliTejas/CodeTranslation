#include <bits/stdc++.h>
using namespace std;

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

int main() {
      COMinit();
  string N;
  long long x,y,ans,z,p,f,l;
  int K;
  int u;
  cin >>N>>K;
  l=N.length();
  ans=0;
  f=0;
  p=1;
  int a[101][3];
  a[0][0]=0;
  a[0][1]=0;
  a[0][2]=0;

  for(int i=0;i<l;i++){
    if(N[i]!='0'){
      f++;
      u=N[i]-'0';
      if(K-f==2){
      ans+=COM(l-i-1,3)*729+(u-1)*COM(l-i-1,2)*81;
      }
      else if(K-f==1){
      ans+=COM(l-i-1,2)*81+(u-1)*COM(l-i-1,1)*9;
      }
       else if(K-f==0){
      ans+=COM(l-i-1,1)*9+(u-1)*COM(l-i-1,0)+1;
      }
    }

  }
    cout<<ans<<endl;
}