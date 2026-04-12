#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
NMはTLEだな
K=2
(x1-x2)+(y1-y2)+
(x1-x3)+(y1-y3)+
(x1-x4)+(y1-y4)+...
(x1-xK)+(y1-yK)+
(x2-x3)+(y2-y3)+...
(x2-xK)+(y2-yK)+...
(x3-x4)+(y3-y4)+...
(x3-xK)+(y3-yK)+...
(x(K-1)-xK)+(y(K-1)+yK)

nCkはいりそう、
多すぎてどうしよう
効率化みえん
(n*mC2)*(n*mCk)通り
全盤面をK倍とか、だったら･･･
こりゃわからんわ

2点決める。K-2の組み合わせだけその2点間の距離の和がとられる。
2点の距離の決め方は（M-d)*N^2で、d=0~M-1まである。0は除いてOK

*/
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
int main(){
  COMinit();
  ll N,M,K,ans=0; cin>>N>>M>>K;
  //Xについて
  ll n=COM(N*M-2,K-2);
  for(ll d=1; d<=M-1; d++){
    ll tmp=1;
    (tmp*=d)%=MOD;
    (tmp*=(M-d))%=MOD;
    (tmp*=N)%=MOD;
    (tmp*=N)%=MOD;
    (tmp*=n)%=MOD;
    (ans+=tmp)%=MOD;
  }
  for(ll d=1; d<=N-1; d++){
    ll tmp=1;
    (tmp*=d)%=MOD;
    (tmp*=(N-d))%=MOD;
    (tmp*=M)%=MOD;
    (tmp*=M)%=MOD;
    (tmp*=n)%=MOD;
    (ans+=tmp)%=MOD;
  }
  cout<<ans<<endl;
}