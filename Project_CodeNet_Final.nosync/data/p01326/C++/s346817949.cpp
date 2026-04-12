#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

typedef long long ll;
ll M = 1000000LL;

int main() {
  int n;
  while(cin >> n, n) {
    char c[n*8];
    REP(i,n*8) {
      cin >> c[i];
    }
    int dfa[21][4];
    memset(dfa,-1,sizeof(dfa));
    dfa[0][0]=5;dfa[0][1]=1;
    dfa[1][1]=2;
    dfa[2][0]=6;dfa[2][1]=3;
    dfa[3][0]=9;dfa[3][1]=4;
    dfa[4][0]=14;
    dfa[5][0]=5;dfa[5][1]=5;dfa[5][2]=0;dfa[5][3]=0;
    dfa[6][0]=6;dfa[6][1]=7;
    dfa[7][0]=dfa[7][1]=7;dfa[7][2]=dfa[7][3]=8;
    dfa[8][0]=dfa[8][1]=8;dfa[8][2]=dfa[8][3]=0;
    dfa[9][0]=9;dfa[9][1]=10;dfa[9][2]=11;dfa[9][3]=12;
    dfa[10][0]=dfa[10][1]=10;dfa[10][2]=dfa[10][3]=12;
    dfa[11][1]=12;
    dfa[12][0]=dfa[12][1]=12;dfa[12][2]=dfa[12][3]=13;
    dfa[13][0]=dfa[13][1]=13;dfa[13][2]=dfa[13][3]=0;
    dfa[14][0]=14;dfa[14][1]=15;dfa[14][2]=16;dfa[14][3]=17;
    dfa[15][0]=dfa[15][1]=15;dfa[15][2]=dfa[15][3]=17;
    dfa[16][0]=16;dfa[16][1]=17;
    dfa[17][0]=dfa[17][1]=17;dfa[17][2]=dfa[17][3]=18;
    dfa[18][0]=dfa[18][1]=18;dfa[18][2]=dfa[18][3]=19;
    dfa[19][0]=dfa[19][1]=19;dfa[19][2]=dfa[19][3]=0;
    // 0 nÜè@1 PªPÂA±@2 PªQÂA±@3 PªRÂA±@4 1ªSÂA±
    // 5 PoCg¶@6 QoCg¶@7 QoCg¶P è 8 QoCg¶QoCgÚ
    // 9 RoCg¶@10 RoCg¶P è@11 RoCg¶PÈµQoCgÚ@12 RoCg¶P èQoCgÚ@13 RoCg¶RoCgÚ
    // 14 SoCg¶@15 SoCg¶P è@16 SoCg¶PÈµQoCgÚ@17 SoCg¶P èQoCgÚ
    // 18 SoCg¶RoCgÚ@19 SoCg¶SoCgÚ
    ll dp[n*8+1][21];             // dp[i][j] : i ¶ÚÜÅ©ÄADFA ÌóÔ j É¢éÆ«ÌgÝí¹
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    REP(i,n*8) {
      REP(j,21) {
        // æªÌ"10"
        if (i%8 == 0 && (j==8||(11<=j&&j<=13)||(16<=j&&j<=19))) {
          if (c[i] != '0') dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % M;
          continue;
        }
        if (i%8 == 1 && (j==8||(11<=j&&j<=13)||(16<=j&&j<=19))) {
          if (c[i] != '1') dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % M;
          continue;
        }
        // SoCg¶QoCgÚÌQÂÚÌy
        if (i%8 == 3 && j == 16) {
          if (c[i] != '0') dp[i+1][17] = (dp[i+1][j] + dp[i][j]) % M;
          continue;
        }
        
        if (c[i] != '1') {
          if (i%8==7) {
            if (dfa[j][2] != -1)
              dp[i+1][dfa[j][2]] = (dp[i+1][dfa[j][2]] + dp[i][j]) % M;
          } else {
            if (dfa[j][0] != -1) {
              dp[i+1][dfa[j][0]] = (dp[i+1][dfa[j][0]] + dp[i][j]) % M;
            }
          }
        }
        if (c[i] != '0') {
          if (i%8==7) {
            if (dfa[j][3] != -1)
              dp[i+1][dfa[j][3]] = (dp[i+1][dfa[j][3]] + dp[i][j]) % M;
          } else {
            if (dfa[j][1] != -1) {
              dp[i+1][dfa[j][1]] = (dp[i+1][dfa[j][1]] + dp[i][j]) % M;
            }
          }
        }
      }
    }
    // REP(i, 21) {
    //   printf("%d : %d\n", i,dp[n*8][i]);
    // }
    cout << dp[n*8][0] << endl;
  }
}