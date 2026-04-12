#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;


int main(void){
  int k,i,j,dp[105][2][4]={};
  string n;
  
  cin >> n >> k;
  dp[0][1][0]=1;
  for (i=0;i<n.size();i++){
    dp[i+1][0][0]=1;
    for (j=1;j<=3;j++){
      if (n[i]!='0') dp[i+1][0][j]+=dp[i][1][j];
      dp[i+1][0][j]+=dp[i][0][j-1]*9+dp[i][0][j];
      dp[i+1][0][j]+=dp[i][1][j-1]*max(0,n[i]-'0'-1);
      if (n[i]=='0') dp[i+1][1][j]=dp[i][1][j];
      else dp[i+1][1][j]=dp[i][1][j-1];
    }
  }
  
  cout << dp[n.size()][0][k]+dp[n.size()][1][k] << endl;
  
  return 0;
}