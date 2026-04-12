#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;
  int k, l;
  cin >> k;
  l = n.size();
  
  int dp[105][5][2] = {};
  dp[0][0][0] = 1;
  int d;
  for(int i=0; i<l; i++){
    d = n.at(i) - '0';
    for(int j=0; j<=k; j++){
      for(int smaller=0; smaller<2; smaller++){
        for(int x=0; x <= (smaller ? 9 : d); x++){
          dp[i+1][x ? j+1 : j][smaller || x < d] += dp[i][j][smaller];
        }
      }
    }
  }
  cout << dp[l][k][0] + dp[l][k][1] << endl;
}