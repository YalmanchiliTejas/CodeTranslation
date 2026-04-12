#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int k,i,j,dp[2][105][4]={};
  string n;
  
  cin >> n >> k;
  
  dp[1][0][0]=1;
  for (i=1;i<=n.size();i++){
    dp[0][i][0]=1;
    for (j=1;j<=3;j++){
      if (n[i-1]!='0') dp[1][i][j]=dp[1][i-1][j-1];
      else dp[1][i][j]=dp[1][i-1][j];
      dp[0][i][j]+=dp[0][i-1][j]+dp[0][i-1][j-1]*9;
      if (n[i-1]!='0') dp[0][i][j]+=dp[1][i-1][j]+dp[1][i-1][j-1]*max(0,n[i-1]-'1');
    }
  }
  
  cout << dp[0][n.size()][k]+dp[1][n.size()][k] << endl;
  
  return 0;
}