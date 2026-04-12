#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
const int MAX_V = 10000;
typedef pair<int, int>P;
#define MOD (ll)1000000007
int main() {
  string K;
  int D;
  cin>>K>>D;
  ll dp[10010][D][2];
  rep(i,10010){
    rep(j,D){
      dp[i][j][0]=0ll;
      dp[i][j][1]=0ll;
    }
  }
  dp[0][0][0]=1ll;
  rep(i,K.size()){
    int x=K[i]-'0';
    rep(j,D){
      rep(k,10){
        if(j+k<D){dp[i+1][j+k][1]+=dp[i][j][1];dp[i+1][j+k][1]%=MOD;}
        else{dp[i+1][(j+k)%D][1]+=dp[i][j][1];dp[i+1][(j+k)%D][1]%=MOD;}
      }
      rep(k,x){
        if(j+k<D){dp[i+1][j+k][1]+=dp[i][j][0];dp[i+1][j+k][1]%=MOD;}
        else{dp[i+1][(j+k)%D][1]+=dp[i][j][0];dp[i+1][(j+k)%D][1]%=MOD;}
      }
        if(j+x<D){dp[i+1][j+x][0]+=dp[i][j][0];dp[i+1][j+x][0]%=MOD;}
        else{dp[i+1][(j+x)%D][0]+=dp[i][j][0];dp[i+1][(j+x)%D][0]%=MOD;}
    }
  }
  ll ans=dp[K.size()][0][0]+dp[K.size()][0][1]-1ll;
  ans%=MOD;
  ans+=MOD;
  ans%=MOD;
   cout<<ans;
}