#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[2][5][105];

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

  string s;cin>>s;int k;cin>>k;

  dp[0][0][0]=1;
  for(int i=1;i<=s.size();i++){
    char c = s[i-1];
    int t = s[i-1]-'0';
    if(i>=2)dp[1][0][i-1]=1;
    if(t==0){
      for(int j=0;j<=k;j++){
        dp[0][j][i]+=dp[0][j][i-1];
        dp[1][j][i]+=dp[1][j][i-1];
        dp[1][j+1][i]+=dp[1][j][i-1] * 9;
      }
    } else {
      for(int j=0;j<=k;j++){
        dp[1][j][i]+=dp[0][j][i-1];
        dp[1][j][i]+=dp[1][j][i-1];
        dp[0][j+1][i]+=dp[0][j][i-1];
        dp[1][j+1][i]+=dp[0][j][i-1] * (t-1);
        dp[1][j+1][i]+=dp[1][j][i-1] * 9;
      }
    }
  }

  cout<<dp[0][k][s.size()]+dp[1][k][s.size()]<<endl;
  
  return 0;
}
