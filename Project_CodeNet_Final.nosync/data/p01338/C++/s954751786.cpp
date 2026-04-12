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

int main() {
  int score[] = {0, 0, 60, 70, 80};
  int n;
  cin>>n;
  while(n--) {
    int ba[5][5];
    REP(y,5)
      REP(x,5)
      cin >> ba[x][y];
    int dp[4][1<<2*4];          // dp[i][S] = i ツ行ツ姪堋づ個スツイツッツチツづーツ湘ウツ妥粘 ツづ可つオツつスツづつォツづ景 ツ行ツ姪堋づ慊づづ個スツコツアツづ個催妥・ツ値
                                // S ツづ債、ツビツッツトツ療アツづーツ２ツビツッツトツつクツづつづ可閉ェツつッツつスツづつォツ、i ツ氾板姪堋づ個グツδ仰ーツプツつェi ツ古つ姪堋づ個スツイツッツチツづーツ可スツ嘉アツ可淞つオツつスツつゥツづーツ表ツつキ
    memset(dp,0,sizeof(dp));
    REP(S, 1<<2*4) {
      REP(x,5) {
        int sc = ba[x][0];
        if (sc==0) continue;
        if (x>0) sc += S>>2*x-2 & 3;
        if (x<4) sc += S>>2*x & 3;
        while(sc>4) sc -= 4;
        dp[0][S] += score[sc];
      }
    }
    for (int i=1; i<4; ++i) {
      REP(S, 1<<2*4) {          // ツ１ツ行ツ前ツづ個スツイツッツチツづ個湘ウツ妥板。
        REP(T, 1<<2*4) {        // ツ個サツ催敖づ個行ツづ個スツイツッツチツづ個湘ウツ妥板。
          int now = dp[i-1][S];
          REP(x,5) {
            int sc = ba[x][i];
            if (sc==0) continue;
            if (x>0) sc += (S>>2*x-2 & 3) + (T>>2*x-2 & 3);
            if (x<4) sc += (S>>2*x & 3) + (T>>2*x & 3);
            while(sc>4) sc -= 4;
            now += score[sc];
          }
          dp[i][T] = max(dp[i][T], now);
        }
       }
    }
    int ans = 0;
    REP(S, 1<<2*4) {
      int now = dp[3][S];
      REP(x,5) {
        int sc = ba[x][4];
        if (sc==0) continue;
        if (x>0) sc += S>>2*x-2 & 3;
        if (x<4) sc += S>>2*x & 3;
        while(sc>4) sc -= 4;
        now += score[sc];
      }
      ans = max(ans, now);
    }
    cout << ans << endl;
  }
}