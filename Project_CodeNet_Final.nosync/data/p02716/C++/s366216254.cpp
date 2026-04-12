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

const int INF = 1e16;
const int MOD = 1e9 + 7;
// const lint LINF = 1e18;
const double eps = 0.000000001;  //もとの値の10^(-16)まで

using namespace std;

// typedef pair<int, int> P;
// priority_queue< P, vector<P>, greater<P> > q;//ダイクストラの時、greaterで小さい順
// cout << fixed << setprecision(10) << ans << endl;
// int gcd(int a,int b){return b?gcd(b,a%b):a;}
int a[300000];
int dp[300000][2][3];

signed main() {
  int n;
  cin >> n;
  REP(i, n) {
    cin >> a[i + 1];
  }
  dp[0][1][0] = -INF;
  dp[0][1][1] = -INF;
  dp[0][1][2] = -INF;
  dp[0][0][1] = -INF;
  dp[0][0][2] = -INF;
  for(int i = 1; i <= n; i++) {
    REP(k, 3) {
      if(n % 2 == 0 && k == 2) continue;
      dp[i][0][0] = dp[i - 1][1][0];
      dp[i][1][0] = dp[i - 1][0][0] + a[i];
      dp[i][0][1] = max(dp[i - 1][0][0], dp[i - 1][1][1]);
      dp[i][1][1] = dp[i - 1][0][1] + a[i];
      dp[i][0][2] = max(dp[i - 1][0][1], dp[i - 1][1][2]);
      dp[i][1][2] = dp[i - 1][0][2] + a[i];
    }
  }
  int ans = -INF;
  //REP(i, n+1) {
    int anss0 = -INF;
    int anss1 = -INF;
    int anss2 = -INF;


    REP(j, 2) {
      REP(k, 3) {
        //anss0 = max(anss0, dp[i][j][0]);
        //anss1 = max(anss1, dp[i][j][1]);
        //anss2 = max(anss2, dp[i][j][2]);
        //if(n % 2 == 0 && k == 2) continue;
        if(n%2==0){
            ans = max(ans, dp[n][j][1]);
            ans = max(ans, dp[n-1][1][0]);
        }
        else{
            ans = max(ans, dp[n][j][2]);
            ans = max(ans, dp[n-1][1][1]);
            ans = max(ans, dp[n-2][1][0]);
        }
      }
    //}
    //cout << "i=" << i << " " <<  anss0 << " "<< anss1 << " " << anss2 <<  endl;
  }
  cout << ans << endl;
  return 0;
}