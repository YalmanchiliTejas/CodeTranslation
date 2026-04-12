#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <stack>
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
typedef long long int ll;
const ll  MOD = 1000000007;
//typedef pair<ll,ll> P;

ll N,A,B,C,D;
ll P[1010][1010];
ll dp[1010][1010];
ll kaijo[1010];
ll i_kaijo[1010];

ll pow(ll x , ll n){
  ll ret = 1;
  while(n>0){
    if(n & 1){
      ret = (ret * x) % MOD;
    }
    x = (x*x) % MOD;
    n >>= 1;
  }
  return ret;
}
int main(){
  cin >> N >> A >> B >> C >> D;
  rep(i,N+1){
    rep(j,i+1){
      if(i==0){
        P[i][j] = 1;
      }
      else if(j == 0){
        P[i][j] = 1;
      }
      else{
        P[i][j] = (P[i][j-1] * (i-j+1)) % MOD; 
      }
      //cout << P[i][j] << " ";
    }
    //cout << endl;
  }
  kaijo[0] = 1;
  i_kaijo[0] = 1;
  rep(i,N){
    kaijo[i+1] = (kaijo[i]*(i+1)) % MOD;
    i_kaijo[i+1] = pow(kaijo[i+1],MOD-2);
    //cout << kaijo[i+1] << " " << i_kaijo[i+1] << endl;
  }
  rep(i,A){
    dp[i][0] = 1;
  }

  for(ll i=A;i<=B;i++){
    for(ll j=0;j<=N;j++){
      for(ll k=0;k<=D;k++){
        if(k>0 && k<C) continue;
        if(j-i*k < 0) break;
        ll tmp = (dp[i-1][j-i*k]*P[N-j+i*k][i*k])%MOD;
        tmp = (tmp*pow(i_kaijo[i],k)) %MOD;
        tmp = (tmp*i_kaijo[k]) % MOD;
        dp[i][j] = (dp[i][j]+tmp)%MOD;
      }
      //cout << dp[i][j] << " ";
    }
    //cout << endl;
  }
  cout << dp[B][N] << endl;
}
