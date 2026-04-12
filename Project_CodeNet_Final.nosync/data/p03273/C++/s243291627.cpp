#include <cmath>
#include <cstdio>
#include <limits>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <string>
#include <array>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  ll h, w;
  cin >> h >> w;
  vector<string> s(h);
  string white = string(w, '.');
  vector<string> ans1;
  rep(i, h) {
    cin >> s.at(i);
    if (s.at(i) != white) ans1.push_back(s.at(i));
  }

  vector<string> ans2(ans1.size());
  rep(j, w) {
    bool is_white = true;
    rep(i, ans1.size()) {
      if (ans1.at(i).at(j) == '#') is_white = false;
    }
    if (!is_white) {
      rep(i, ans1.size()) {
        ans2.at(i).push_back(ans1.at(i).at(j));
      }
    }
  }

  rep(i, ans1.size()) {
    cout << ans2.at(i) << endl;
  }

  return 0;
}