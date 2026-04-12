#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h);
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;
      if (c == 'B') a[i].push_back(j);
    }
  }
  vector<pair<int, int>> candi;
  for (int i = 0; i < h; i++) {
    if (a[i].empty()) continue;
    candi.emplace_back(i, a[i][0]);
    candi.emplace_back(i, a[i].back());
  }
  int ans = 0;
  for (int i = 0; i < (int) candi.size(); i++) {
    for (int j = 0; j < (int) candi.size(); j++) {
      ans = max(ans, abs(candi[i].first - candi[j].first) + abs(candi[i].second - candi[j].second));
    }
  }
  cout << ans << endl;
  return 0;
}
