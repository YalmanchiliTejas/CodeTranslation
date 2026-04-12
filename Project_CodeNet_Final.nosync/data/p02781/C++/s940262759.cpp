#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int dp[105][4][2];

int main(){
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  
  dp[0][0][0] = 1;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < 4; j++){
      for(int m = 0; m < 2; m++){
        for(int d = 0; d < 10; d++){
          int x = s[i]-'0';
          int ni = i+1, nj = j, nm = m;
          if(d != 0) nj++;
          if(nj > k) continue;
          if(nm == 0){
            if(x > d) nm = 1;
            else if(x < d) break;
          }
          dp[ni][nj][nm] += dp[i][j][m];
        }
      }
    }
  }

  cout << dp[n][k][0]+dp[n][k][1] << endl;
  return 0;
}