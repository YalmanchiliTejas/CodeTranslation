#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

int main() {
  int H, W; cin >> H >> W;
  vector<string> a(H);
  REP(i, H) {
    cin >> a[i];
  }

  vector<string> ans;
  REP(i, H) {
    bool flag = false;
    REP(k, W) {
      if(a[i][k] == '#') flag = true;
    }
    if(flag) ans.push_back(a[i]);
  }

  vector<vector<string>> ans2;
  REP(i, W) {
    bool flag = false;
    REP(k, ans.size()) {
      if(ans[k][i] == '#') flag = true;
    }
    if(flag) {
      vector<string> tmp;
      REP(k, ans.size()) {
        tmp.push_back(char_to_string(ans[k][i]));
      }
      ans2.push_back(tmp);
      tmp.clear();
    }
  }

  REP(i, ans.size()) {
    REP(k, ans2.size()) {
      cout << ans2[k][i];
    }
    cout << endl;
  }
}