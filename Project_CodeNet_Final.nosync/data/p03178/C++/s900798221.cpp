#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

ll dp[101010][111][2];

int main(){
  string K; cin>>K;
  int D; cin>>D;
  reverse(K.begin(),K.end());
  dp[K.length()][0][0]=1;
  for(int i=K.length()-1;i>=0;i--) rep(j,D){
    int num=K[i]-'0';
    rep(k,10){
      (dp[i][(j+k)%D][1]+=dp[i+1][j][1])%=MOD;
      if(k<num) (dp[i][(j+k)%D][1]+=dp[i+1][j][0])%=MOD;
      if(k==num) (dp[i][(j+k)%D][0]+=dp[i+1][j][0])%=MOD;
    }
  }
  cout<<(dp[0][0][0]+dp[0][0][1]-1+MOD)%MOD<<endl;
  return 0;
}
