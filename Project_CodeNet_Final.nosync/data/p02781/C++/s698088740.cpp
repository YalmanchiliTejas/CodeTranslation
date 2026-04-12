#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  string n;
  int k;
  cin >> n >> k;
  int leng = n.size();
  
  vector<vector<int>> dp0(101, vector<int>(101, 0));
  vector<vector<int>> dp1(101, vector<int>(101, 0));

  // initialize
  for(int j = 0; j <= k; j++){
    dp0[0][j] = 0;
    dp1[0][j] = 0;
  }
  dp0[1][0] = 1;
  dp0[1][1] = n[0] - '0' - 1;
  dp1[1][0] = 0;
  dp1[1][1] = 1;
  for(int j = 2; j <= k; j++){
    dp0[1][j] = 0;
    dp1[1][j] = 0;
  }

  for(int i = 2; i <= leng; i++){
    for(int j = 0; j <= k; j++){
      if(j == 0){
        dp0[i][j] = dp0[i-1][j] * 1;
        if(n[i-1]-'0' != 0) dp1[i][j] = 0;
        else dp1[i][j] = dp1[i][j-1];
      }else{
        dp0[i][j] = dp0[i-1][j-1]*9 + dp0[i-1][j];
        if(n[i-1]-'0' > 1) dp0[i][j] += dp1[i-1][j-1] * (n[i-1]-'0' - 1) + dp1[i-1][j];
        else if(n[i-1] - '0' == 1) dp0[i][j] += dp1[i-1][j];
        if(n[i-1]-'0' != 0) dp1[i][j] = dp1[i-1][j-1];
        else dp1[i][j] = dp1[i-1][j];
      }
    }
  }

  cout << dp0[leng][k] + dp1[leng][k] << endl;

  return 0;
}