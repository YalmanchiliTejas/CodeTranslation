#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;
const ll mod = 1e9+7;

// i: 左からみた桁数(0桁あり), j: 非ゼロの使用回数, k: 0:最大値の可能性あり 1: なし
int dp[101][4][2];

int main(int argc, char const* argv[])
{
  string n;
  cin>>n;

  int ndigits = n.size();
  int K;
  cin>>K;

  dp[0][0][0] = 1;
  REP(i,ndigits)REP(j,4)REP(k,2) {
    // printf("i: %d, j: %d, k: %d\n", i, j, k);
    // nd: nの今の桁のdigit
    int nd = n[i]-'0';
    // d: 次の桁のdigit
    REP(d,10) {
      // ni: 次の桁の位置
      // nj: 次の桁まででの非ゼロの数
      // nk: 次の桁まででの最大かどうかの状態
      int ni = i+1, nj = j, nk = k;
      // 次の桁のdigitが0でないなら非ゼロの数を増やす
      if(d!=0) nj++;
      // 使用できる非ゼロの数より多くなるなら遷移しない
      if(nj>K) continue;
      // 最大値の可能性がある場合
      if(k==0) {
        // 最大値を超えるので遷移しない
        if(d>nd) continue;
        // 最大値より小さくなるのでkを遷移させる
        if(d<nd) nk = 1;
      }
      dp[ni][nj][nk] += dp[i][j][k];
      // printf("d: %d, dp[%d][%d][%d]: %d -> dp[%d][%d][%d]: %d\n", d, i, j, k, dp[i][j][k], ni, nj, nk, dp[ni][nj][nk]);
    }
    // printf("\n");
  }

  // printf("dp[n][K][0]: %d\n", dp[ndigits][K][0]);
  // printf("dp[n][K][1]: %d\n", dp[ndigits][K][1]);

  int ans = dp[ndigits][K][0] + dp[ndigits][K][1];
  cout << ans << endl;

  return 0;
}
