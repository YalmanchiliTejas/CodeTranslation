#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()


int main(){
  string N;cin>>N;
  int K;cin>>K;
  int dp[110][2][4];
  rep(i,110)rep(j,2)rep(k,K+1)dp[i][j][k]=0;
  dp[0][0][0]=1;
  rep(i,N.size()){
    rep(smaller,2){
      rep(condition,4){
        for(int j=0;j<=(smaller ? 9 : (N[i]-'0'));++j){
          if((condition + !!j) >= 4) continue;
          dp[i + 1][smaller || j < (N[i]-'0')][condition + !!j] += dp[i][smaller][condition];
          //cout << "dp" << dp[i][smaller][condition] << endl;
        }
      }
    }
  }
  //cout << "N " << N.size() << K << endl;
  //cout << " " << dp[N.size()][0][K] << " " << dp[N.size()][1][K] << endl;
  cout << dp[N.size()][0][K] + dp[N.size()][1][K] << endl;
}