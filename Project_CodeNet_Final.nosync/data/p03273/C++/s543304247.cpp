#include <bits/stdc++.h>
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define DEC(i, a, b) for (int i = (a); i > (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
typedef long long ll;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
const ll LINF = (int)1e18;
const double EPS = 1e-9;

signed main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int H,W;
  cin >> H >> W;
  vector<string> a(H);
  REP(i,H) {
    cin >> a[i];
  }

  vector<string> ans;
  REP(i,H) {
    bool flg = false;
    for (auto c: a[i]) {
      if (c == '#') flg = true;
    }
    if (flg) {
      ans.pb(a[i]);
    } 
  }

  int j = 0;
  while(j < W) {
    bool flg = true;
    for (auto l: ans) {
      if (l[j] != '.') flg = false;
    }
    if (flg) {
      for (auto &l: ans) {
        l.erase(j,1);
      } 
      --W;
    } else ++j;
  }
  
  for (auto l: ans) {
    cout << l << endl;
  }
  return 0;
}