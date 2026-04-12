#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;

int dp[105][4][2];

ll choose(ll l, ll r){
  if(l < r || r <= 0 || l <= 0) return 0;
  ll ret = 1;
  for(ll i = l; i >= l - r + 1; i--){
    ret *= i;
  }
  for(ll i = r; i >= 1; i--){
    ret /= i;
  }
  return ret;
}

void solve(){
  string s; cin >> s;
  int x; cin >> x;
  int n = s.size();
  dp[0][0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 2; k++){
        for(int d = 0; d < 10; d++){
          int nd = s[i] - '0', ni = i + 1, nj = j, nk = k;
          if(d != 0) nj++;
          if(nj > x) continue;
          if(k == 0){
            if(d > nd) continue;
            if(d < nd) nk = 1;
          }
          dp[ni][nj][nk] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[n][x][0] + dp[n][x][1] << endl;


  return;
}

int main(){
  solve();
  return 0;
}
