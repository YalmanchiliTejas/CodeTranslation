#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll dp[102][2][5] = {};

int main() {
  string n;
  int k;
  cin >> n;
  cin >> k;
  int len = n.size();
  dp[0][0][0] = 1LL;
  rep(i, len){
    rep(j, 4) { 
        dp[i + 1][1][j] += dp[i][1][j]; //0追加
        dp[i + 1][1][j + 1] += dp[i][1][j] * 9; //1~9追加

        ll ni = n[i] - '0';
        if(ni!=0LL){
          dp[i + 1][1][j] += dp[i][0][j]; //60
          dp[i + 1][1][j + 1] += dp[i][0][j] * (ni - 1LL); //61~62
        }

        if(ni==0LL){
          dp[i + 1][0][j] += dp[i][0][j];
        }else{
          dp[i + 1][0][j + 1] += dp[i][0][j];
        }
    }
  }
  cout << dp[len][1][k] + dp[len][0][k] << endl;
  return 0;
}