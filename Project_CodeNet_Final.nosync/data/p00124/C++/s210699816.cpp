#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> T;

int main() {
  int n;
  bool f = false;
  while (cin >> n, n) {
    string s;
    int w, L, d;
    vector<T> v;
    for (int i = 0; i < n; i++) {
      cin >> s >> w >> L >> d;
      v.emplace_back(s, w * 3 + d);
    }
    sort(v.begin(), v.end(), [](const auto& x, const auto& y) {return x.second > y.second;});
    if (f) cout << "\n";
    for (auto& e : v) {
      cout << e.first << "," << e.second << "\n";
    }
    f = true;
  }
}
