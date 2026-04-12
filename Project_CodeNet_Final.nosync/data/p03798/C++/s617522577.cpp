#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i, j;
  string s;
  cin >> n >> s;
  
  vector<vector<char>> dp(4, vector<char>(n));
  dp[0][0] = dp[0][1] = dp[1][0] = dp[2][1] = 'S';
  dp[1][1] = dp[2][0] = dp[3][0] = dp[3][1] = 'W';
  for(i = 0; i < 4; i++){
    for(j = 1; j < n - 1; j++){
      
      if(dp[i][j] == 'S'){
        if(s.at(j) == 'o') dp[i][j + 1] = dp[i][j - 1];
        else{
          if(dp[i][j - 1] == 'S') dp[i][j + 1] = 'W';
          else dp[i][j + 1] = 'S';
        }
      }
      
      if(dp[i][j] == 'W'){
        if(s.at(j) == 'x') dp[i][j + 1] = dp[i][j - 1];
        else{
          if(dp[i][j - 1] == 'S') dp[i][j + 1] = 'W';
          else dp[i][j + 1] = 'S';
        }
      }
      
    }
  }
  
  int ans = 1, ans2 = 1;
  for(i = 0; i < 4; i++){
    if(dp[i][n - 1] == 'S'){
      if(s.at(n - 1) == 'o' && dp[i][n - 2] == dp[i][0]){
        ans *= i + 2;
      }
      else if(s.at(n - 1) == 'x' && dp[i][n - 2] != dp[i][0]){
        ans *= i + 2;
      }
    }
    else{
      if(s.at(n - 1) == 'x' && dp[i][n - 2] == dp[i][0]){
        ans *= i + 2;
      }
      else if(s.at(n - 1) == 'o' && dp[i][n - 2] != dp[i][0]){
        ans *= i + 2;
      }
    }
  }
  for(i = 0; i < 4; i++){
    if(dp[i][0] == 'S'){
      if(s.at(0) == 'o' && dp[i][1] == dp[i][n - 1]){
        ans2 *= i + 2;
      }
      else if(s.at(0) == 'x' && dp[i][1] != dp[i][n - 1]){
        ans2 *= i + 2;
      }
    }
    else{
      if(s.at(0) == 'x' && dp[i][1] == dp[i][n - 1]){
        ans2 *= i + 2;
      }
      else if(s.at(0) == 'o' && dp[i][1] != dp[i][n - 1]){
        ans2 *= i + 2;
      }
    }
  }
  
  if(ans % 5 == 0 && ans2 % 5 == 0){
    for(j = 0; j < n; j++){
      cout << dp[3][j];
    }
    cout << endl;
  }
  else if(ans % 4 == 0 && ans2 % 4 == 0){
    for(j = 0; j < n; j++){
      cout << dp[2][j];
    }
    cout << endl;
  }
  else if(ans % 3 == 0 && ans2 % 3 == 0){
    for(j = 0; j < n; j++){
      cout << dp[1][j];
    }
    cout << endl;
  }
  else if(ans % 2 == 0 && ans2 % 2 == 0){
    for(j = 0; j < n; j++){
      cout << dp[0][j];
    }
    cout << endl;
  }
  else cout << -1 << endl;
}