#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
ll dp[10005][100][2];

int main(){
  string s;
  cin >> s;
  int N = s.size();
  int D;
  cin >> D;

  dp[0][0][0] = 1;
  for(int i = 0; i < N; i++){
    int num = s[i] - '0';
    for(int j = 0; j < D; j++){
      dp[i + 1][(j + num) % D][0] = dp[i][j][0];
    }
    for(int j = 0; j < D; j++){
      for(int k = 0; k < num; k++){
        dp[i + 1][(j + k) % D][1] += dp[i][j][0];
      }
      for(int k = 0; k < 10; k++){
        dp[i + 1][(j + k) % D][1] += dp[i][j][1];
      }
      dp[i + 1][j][0] %= MOD;
      dp[i + 1][j][1] %= MOD;
    }
  }

  /*for(int i = 0; i <= N; i++){
    for(int j = 0; j < D; j++){
      cout << dp[i][j][0] << " ";
    }
    cout << endl;
    for(int j = 0; j < D; j++){
      cout << dp[i][j][1] << " ";
    }
    cout << endl;

  }*/

  cout << (dp[N][0][0] + dp[N][0][1] - 1) % MOD << endl;
  return 0;
}