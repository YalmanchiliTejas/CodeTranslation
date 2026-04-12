#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  string n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> a;
//ベクターnを構成
  for(auto p : n){
    a.push_back(p-'0');
  }
  /*
  for (int i = 0; i < n.length(); i++){
    cout << a[i];
  }
  cout << endl;
  */
  int dp[105][3][5] = {0}; //今調べている桁をi、未満フラグをsmaller、0以外が出た個数をm
  dp[0][0][0] = 1;
  dp[0][0][1] = 0;
  dp[0][1][0] = 0;
  dp[0][1][1] = 0;

  for (int i = 0; i < n.length(); i++){
    for (int j = 0; j < 2; j++){
      for(int m = 0; m <= k; m++){
        int tmp;
        if(j == 1){
          tmp = 9;
        }else{
          tmp = a[i];
        }
        for (int x = 0; x <= tmp; x++){
          //未満か
          //cout << x << " ";
          /*
          if (j == 1){
            dp[i + 1][j][m] += dp[i][j][m];
          }else if(x == a[i] && j == 0){
            //dp[i + 1][j][m] += dp[i][j][m];
          }else if(x < a[i] && j == 0){
            dp[i + 1][1][m] += dp[i][0][m];
          }
          //既に0以外がいくつ出たか
          if(x == 0){
            dp[i + 1][j][m] += dp[i][j][m];
          }else if (x != 0){
            dp[i + 1][j][m + 1] += dp[i][j][m];
          }
          */
          //dp[i + 1][j || x < a[i]][m || x != 0] += dp[i][j][m];
          dp[i + 1][j || x < a[i]][m + (x != 0)] += dp[i][j][m];
        }
        
      }
    }
  }
  /*
  for (int i = 0; i<=n.length(); i++){
    for (int j = 0; j < 2; j++){
      for (int m = 0; m <= k; m++){
        cout << dp[i][j][m] << " ";
      }
      cout << " ";
    }
    cout << endl;
  }
  */
  cout << dp[n.length()][0][k] + dp[n.length()][1][k] << "\n";


  return 0;
}