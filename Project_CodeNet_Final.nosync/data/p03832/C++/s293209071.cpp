#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

const int MAX_N=1010;
ll inv[MAX_N+1], fact[MAX_N+1], ifact[MAX_N+1];

ll comb(int n, int k){
  if(n<k) return 0;
  return fact[n]*ifact[k]%MOD*ifact[n-k]%MOD;
}

void prepare(){
  inv[1]=fact[0]=fact[1]=ifact[0]=ifact[1]=1LL;
  for(int i=2;i<=MAX_N;i++){
    inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    fact[i]=fact[i-1]*i%MOD;
    ifact[i]=ifact[i-1]*inv[i]%MOD;
  }
}


// dp[k][n]:n人に対して，k人以下のグループを作った場合のグループ分けの個数
ll dp[1010][1010];

int main(){
  prepare();
  int N,A,B,C,D; cin>>N>>A>>B>>C>>D;
  rep(i,1010) dp[i][0]=1;
  for(int i=A;i<=B;i++) for(int j=1;j<=N;j++){
    dp[i][j]+=dp[i-1][j];
    ll tmp=1;
    for(int k=1;k*i<=j&&k<=D;k++){
      (tmp*=comb(j-(k-1)*i,i))%=MOD;
      if(k>=C)(dp[i][j]+=tmp*dp[i-1][j-i*k]%MOD*ifact[k]%MOD)%=MOD;
    }
  }
  cout<<dp[B][N]<<endl;
  return 0;
}
