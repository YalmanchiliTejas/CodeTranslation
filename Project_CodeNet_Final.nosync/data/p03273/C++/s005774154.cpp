#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W, '0'));
  REP(i, H) REP(j, W) cin >> a[i][j];
  vector<vector<int>> breaked(H, vector<int>(W, 0));
  while (true) {
    bool t = true;
    REP(i, H) {
      int num = -1,cnt=0;
      REP(j, W) {
        if (breaked[i][j] == 1){
          cnt++;
          continue;
      }
        if (a[i][j] != '.') {
          num = j;
          break;
        }
      }
      if (cnt == W) continue;
      if (num == -1) {
        t = false;
        REP(j, W) { breaked[i][j] = 1; }
      }
    }
    REP(i, W) {
      int num = -1,cnt = 0;
      REP(j, H) {
        if (breaked[j][i] == 1) {
          cnt++;
          continue;
        }
        if (a[j][i] != '.') {
          num = j;
          break;
        }
      }
      if (cnt == H) continue;
      if (num == -1) {
        t = false;
        REP(j, H) { breaked[j][i] = 1; }
      }
    }
    if (t) break;
  }
  REP(i, H) {
    bool t = false;
    REP(j, W) {
      
      if (breaked[i][j] != 1){
         cout << a[i][j];
         t = true;
      }
    }
    if (!t) continue;
    cout << endl;
  }
}