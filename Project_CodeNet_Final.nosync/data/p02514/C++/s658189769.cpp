#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define SZ(a) ((int)((a).size()))
#define REPSZ(i,v) REP(i,SZ(v))
#define ALL(a) (a).begin(),(a).end()
template<class T>void pv(T a,T b) {for(T i=a;i!=b;++i)cerr<<*i<<' ';cerr<<endl;}
typedef long long Int;

int C, R;
int table[128][128];
int dp[128][128];

vector<int> pos[128 * 128];

int main() {
  for (;;) {
      memset(table, -1, sizeof(table));
      REP(i, 128 * 128) pos[i].clear();

      cin >> C >> R;
      if (C == 0 && R == 0) break;

      int last = 0;
      REP(r, R) REP(c, C) {
          string w; cin >> w;
          if (w == ".")
              table[r][c] = -1;
          else if (w == "S")
              table[r][c] = 0;
          else if (w == "G") {
              table[r][c] = -2;
          } else {
              int x; sscanf(w.c_str(), "%d", &x);
              last = max(last, x);
              table[r][c] = x;
          }
      }
      const int inf = 1001001001;
      REP(i, 128) REP(j, 128) dp[i][j] = inf;

      REP(r, R) REP(c, C) {
          if (table[r][c] == -2) table[r][c] = last + 1;
          if (table[r][c] == 0)
              dp[r][c] = 0;

          if (table[r][c] != -1) {
              pos[table[r][c]].push_back(r * 1000 + c);
          }
      }
      last++;

      for (int d = 1; d <= last; d++) {
          REPSZ(i, pos[d - 1]) {
              int x = pos[d - 1][i] / 1000;
              int y = pos[d - 1][i] % 1000;
              REPSZ(j, pos[d]) {
                  int nx = pos[d][j] / 1000;
                  int ny = pos[d][j] % 1000;
                  dp[nx][ny] = min(dp[nx][ny], dp[x][y] + abs(x - nx) + abs(y - ny));
              }
          }
      }
      cout << dp[pos[last][0] / 1000][pos[last][0] % 1000] << endl;
  }
  return 0;
}