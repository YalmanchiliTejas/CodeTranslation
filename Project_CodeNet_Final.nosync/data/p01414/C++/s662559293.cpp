#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
constexpr int INF = 1000000001;

char color[] = "RGB";

int main() {
  int n;
  cin>>n;
  vector<pair<int,int>> s;
  REP(i,n) {
    int h,w;
    cin>>h>>w;
    s.emplace_back(h,w);
  }
  string t;
  REP(i,4) {
    string s;
    cin>>s;
    t += s;
  }
  vector<int> dp(1<<16, INF);
  dp[0] = 0;
  REP(i,1<<16) {
    REP(j,n) {
      int h,w;
      tie(h,w) = s[j];
      FOR(y,-h+1,4)FOR(x,-w+1,4) {
        int bits = 0;
        REP(k,h)REP(l,w) {
          int py = y + k;
          int px = x + l;
          if (px < 0 || px >=4 || py < 0 || py >= 4) continue;
          int index = px + 4*py;
          if ((i >> index) & 1) continue;
          bits |= 1 << index;
        }
        if (bits == 0) continue;
        REP(k,3) {
          bool ok = true;
          REP(l,16) {
            if ((bits >> l) & 1) {
              if (t[l] != color[k]) {
                ok = false;
                break;
              }
            }
          }
          if (ok) {
            dp[i|bits] = min(dp[i|bits], dp[i] + 1);
          }
        }
      }
    }
  }
  cout << dp[(1<<16)-1] << endl;
  return 0;
}