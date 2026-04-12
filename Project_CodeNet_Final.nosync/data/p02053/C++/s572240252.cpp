// Undone
#include <bits/stdc++.h>
using namespace std;
int H, W; 
int main() {
  cin >> H >> W;
  vector< pair<int, int> > v;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      if (c == 'B') {
        v.push_back(make_pair(i, j));
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    int dist_max;
    if (v[i].first < H/2) {
      if (v[i].second < W/2) {
        dist_max = (H-v[i].first-1)+(W-v[i].second-1);
      } else {
        dist_max = (H-v[i].first-1)+v[i].second;
      }
    } else {
      if (v[i].second < W/2) {
        dist_max = v[i].first + (W-v[i].second-1);
      } else {
        dist_max = v[i].first+v[i].second;
      }
    }

    if (dist_max < ans) continue;

    for (int j = 0; j < v.size(); j++) {
      if (i == j) continue;
      if (dist_max < ans) break;
      ans = max(ans, abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second));
    }
  }
  cout << ans << endl;
}


