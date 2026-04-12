#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h,w;
  cin >> h>>w;
  vector<string> a;
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    if (find(s.begin(), s.end(), '#') != s.end()) {
      a.push_back(s);
    }
  }
  vector<int> crash(w, 0);
  for (auto& e : a) {
    for (int i = 0; i < w; ++i) {
      crash[i] |= e[i] == '#';
    }
  }

  for (auto& e : a) {
    string row;
    for (size_t i = 0; i < e.size(); ++i) {
      if (crash[i] != 0) {
        row.push_back(e[i]);
      }
    }
    cout << row << "\n";
  }
}
