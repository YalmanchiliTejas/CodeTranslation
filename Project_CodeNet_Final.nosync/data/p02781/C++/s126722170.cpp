#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin>>s;
  int k;
  cin>>k;
  int n = s.size();
  
  int dp[105][4][2];
  rep(i,105)rep(j,4)rep(k,2) dp[i][j][k] = 0;
  dp[0][0][0] = 1;
  rep(i,n)rep(j,k+1){
    if(s[i]!='0'){
      dp[i+1][j][1]=dp[i][j][0]+dp[i][j][1];
      if(j) dp[i+1][j][1]+=dp[i][j-1][0]*(s[i]-'1')+dp[i][j-1][1]*9;
      if(j) dp[i+1][j][0]=dp[i][j-1][0];
    }else{
      dp[i+1][j][1]=dp[i][j][1];
      if(j) dp[i+1][j][1]+=dp[i][j-1][1]*9;
      dp[i+1][j][0]=dp[i][j][0];
    }
  }
  
  cout << dp[n][k][0]+dp[n][k][1] << endl;
}
  
