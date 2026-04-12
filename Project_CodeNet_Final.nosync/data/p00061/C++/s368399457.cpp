#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<pair<int, int>> vec;

  int p, s;
  char dummy;
  while (cin >> p >> dummy >> s) {
    if (p == 0)
      break;
    vec.push_back(make_pair(p, s));
  }

  sort(vec.begin(), vec.end(), [](pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
  });

  int q;
  while (cin >> q) {
    int rank = 0;
    int last = 50;
    for (auto &v : vec) {
      if (v.second < last) {
        last = v.second;
        ++rank;
      }
      if (v.first == q) {
        cout << rank << endl;
        break;
      }
    }
  }
}
