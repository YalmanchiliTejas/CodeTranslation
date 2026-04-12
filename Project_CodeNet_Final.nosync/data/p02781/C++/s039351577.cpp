#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define REP(i, n) for(int i = 0; (i) < (n); ++(i))
#define FOR(i, n) for(int i = 1; (i) <= (n); ++(i))
#define dump(x) cout << #x << " = " << (x) << endl;
#define pb push_back
#define int long long

const int INF = 1e18;
const int MOD = 1e9 + 7;
// const lint LINF = 1e18;
const double eps = 0.000000001;  //もとの値の10^(-16)まで

using namespace std;

// typedef pair<int, int> P;
// priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
// cout << fixed << setprecision(10) << ans << endl;
// int gcd(int a,int b){return b?gcd(b,a%b):a;}

int dp[110][2][120];
signed main() {
  string n;
  int k2;
  cin >> n >> k2;
  int nsize = n.size();
  dp[0][0][0] = 1;
  REP(i, nsize) {
    REP(j, 2) {
      REP(k, 5) {
        if(j == 0) {
          for(int x = 0; x <= (int)(n[i] - '0'); x++) {
            if(x==0 && x == (int)(n[i] - '0')){
              dp[i + 1][0][k] += dp[i][j][k];
            }
            else if(x == (int)(n[i] - '0')){
              dp[i + 1][0][k+1] += dp[i][j][k];
            }
            else if(x==0){
              dp[i + 1][1][k] += dp[i][j][k];
            }
            else{
              dp[i + 1][1][k+1] += dp[i][j][k];
            }   
          }
        } else {
          for(int x = 0; x <= 9; x++) {
            if(x==0){
              dp[i + 1][1][k] += dp[i][j][k];
            }
            else{
              dp[i + 1][1][k+1] += dp[i][j][k];
            }
          }
        }
      }
    }
  }
  cout << dp[nsize][0][k2]+dp[nsize][1][k2] << endl;
  return 0;
}