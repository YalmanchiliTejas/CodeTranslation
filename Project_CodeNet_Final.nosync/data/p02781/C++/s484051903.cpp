#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  string s;
  int n;
  cin >> s >> n;
  vector<vector<vector<int>>> dp(s.size()+1,vector<vector<int>>(4,vector<int>(2,0)));
  dp[0][0][0] = 1;
  rep(i,s.size())rep(j,4)rep(k,2){
    rep(l,10){
      int ni = i+1,nj = j,nk = k;
      if(l != 0)nj++;
      if(nj > n)continue;
      if(k == 0){
        if(l > s[i]-'0')continue;
        if(l < s[i]-'0')nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
    }
  }
  cout << dp[s.size()][n][0]+dp[s.size()][n][1] << endl;




  return 0;
}