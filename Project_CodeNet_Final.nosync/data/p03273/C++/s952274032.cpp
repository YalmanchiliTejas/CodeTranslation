#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
typedef long long ll;
/* clang-format off */
#define MOD 1000000007
#define INF 1000000000000000000ll
#define REP(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(a) (a).begin(), (a).end()
//#define __DEBUG__
#ifdef __DEBUG__
#define CH_P(a) cout <<"check_point("<<#a<<")" << "\n";
#define DEBUG(x) cout<<#x<<":"<<x<<"\n"
#define DEBUGS(v) cout << #v << ":";for(auto x:v){cout<<x<<" ";}cout<<"\n"
#endif
#ifndef __DEBUG__
#define CH_P(a) 
#define DEBUG(x) 
#define DEBUGS(v) 
#endif
/* clang-format on */

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) { cin >> s[i]; }
  set<int> eli_h, eli_w;
  REP(j, w) {
    bool f = true;
    REP(i, h) {
      if (s[i][j] == '#') f = false;
    }
    if (f) eli_w.insert(j);
  }
  REP(i, h) {
    bool f = true;
    REP(j, w) {
      if (s[i][j] == '#') f = false;
    }
    if (f) eli_h.insert(i);
  }
  REP(i, h) {
    bool f = false;
    REP(j, w) {
      if (!eli_h.count(i) && !eli_w.count(j)) {
        cout << s[i][j];
        f = true;
      }
    }
    if (f) cout << "\n";
  }
  return 0;
}
