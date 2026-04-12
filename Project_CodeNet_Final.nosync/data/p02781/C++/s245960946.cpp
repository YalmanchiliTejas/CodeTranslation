#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int>P;
typedef tuple<ll,ll,ll>T;
const int MAX = 510000;
const int MOD = 1000000007;
//この設定だとn<10^7が限界。maxの０を一個増やせば100msかかるが一桁増やせる。
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  COMinit();
  string s;
  cin>>s;
  int K;
  cin>>K;
  int N=s.size();
  vector<int>num(N);
  rep(i,N){
    num[i]=s[i]-'0';
  }
  ll ans=0;
  queue<P>qu;
  qu.push(P(0,0));
  qu.push(P(0,1));
  ans+=(num[0]-1)*pow(9,K-1)*COM(N-1,K-1);
  while(!qu.empty()){
    auto t=qu.front();qu.pop();
    int a=t.first,b=t.second;
    if(b==0){
      if(a==N-1){continue;}
      qu.push(P(a+1,0));
      ans+=9*pow(9,K-1)*COM(N-a-2,K-1);
    }
    else{
     
      if(b==K){ans+=1;continue;}
      if(a==N-1){if(b==K)ans+=1;continue;}
    
      int x=num[a+1];
      if(x==0){qu.push(P(a+1,b));}
      else{
      	qu.push(P(a+1,b+1));
        ans+=pow(9,K-b)*COM(N-a-2,K-b);
        ans+=(x-1)*pow(9,K-b-1)*COM(N-a-2,K-b-1);
      }
    }
  }
  cout<<ans;
}