#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
using namespace std;

int rec(int line, vector<vector<int>> g, int depth, vector<int> dp){
  dp[line] = 1;
  if(depth == g[0].size()){
    int check = 0;
    for(int i = 0 ; i < g[0].size(); i++){
      check += dp[i];
    }
    if(check == g[0].size()){
      return 1;
    }else{
      return 0;
    }
  }
  int ans = 0;
  for(int i = 0; i < g[0].size(); i++){
    if(g[line][i] == 1){
      vector<vector<int>> gtmp = g;
      for(int j = 0; j < g[0].size(); j++){
        gtmp[j][i] = 2;
      }
      gtmp[i][line] = 2;
      ans += rec(i, gtmp, depth+1, dp);
    }
  }
  return ans;
}

int main(){

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n,vector<int>(n,0));
  vector<int> dp(n,0);
  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
//    cout << a << b<<endl;
    g[a-1][b-1] = 1;
    g[b-1][a-1] = 1;
  }
  
//  for(int i = 0; i < n; i++){
//    for(int j = 0; j < n; j++){
//      cout << g[i][j] << " ";
//    }
//    cout << endl;
//  }
//
  cout << rec(0,g,1,dp) << endl;;
  return 0;
} 
