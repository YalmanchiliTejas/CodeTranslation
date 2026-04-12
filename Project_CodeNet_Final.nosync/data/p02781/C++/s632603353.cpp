#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  int k = 0;
  string n;
  cin >> n >> k;
  ll dp[10005][2][5];
  dp[0][0][0] = 1;
  int kazu = n.size();
  //cout << kazu << endl;
  for(int i = 0;i <= kazu - 1;i++){
    for(int j = 0;j <= k;j++){
      dp[i + 1][1][j + 1] += dp[i][1][j] * 9;
      dp[i + 1][1][j] += dp[i][1][j];
      int num = 0;
      num = n[i] - '0';
      //cout << num << endl;
      if(num > 0){
        dp[i + 1][1][j + 1] += dp[i][0][j] * (num - 1);
        dp[i + 1][1][j] += dp[i][0][j];
      }
      if(num > 0){
        dp[i + 1][0][j + 1] += dp[i][0][j];
      }
      else{
        dp[i + 1][0][j] += dp[i][0][j];
      }
    }
  }
  cout << dp[kazu][0][k] + dp[kazu][1][k] << endl;
  return 0;
}