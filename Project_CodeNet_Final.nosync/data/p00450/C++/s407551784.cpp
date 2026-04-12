#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> P;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (!n) return 0;
    vector<P> stone;
    for (int i = 0; i < n; i++) {
      int color;
      cin >> color;
      if (i == 0) {
        stone.push_back(P(color, 1));
      } else if (i % 2 == 0) {
        if (stone[stone.size() - 1].first == color) {
          stone[stone.size() - 1].second++;
        } else {
          stone.push_back(P(color, 1));
        }
      } else {
        if (stone[stone.size() - 1].first == color) {
          stone[stone.size() - 1].second++;
        } else {
          stone[stone.size() - 1].second++;
          stone[stone.size() - 1].first = 1 - stone[stone.size() - 1].first;
          if (stone.size() > 1) {
            stone[stone.size() - 2].second += stone[stone.size() - 1].second;
            stone.pop_back();
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < stone.size(); i++) {
      if (stone[i].first == 0) ans += stone[i].second;
    }
    cout << ans << endl;
  }
}

