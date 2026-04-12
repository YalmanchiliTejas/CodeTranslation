#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int H, W, C = 0;
  cin >> H >> W;
  vector<string> table(H);
  REP(i, H) {
    cin >> table.at(i);
    for (auto x : table.at(i))
      if (x == '#') C++;
  }
  if (C != (H - 1) + (W - 1) + 1) {
    cout << "Impossible" << endl;
    return 0;
  }
  int h = 0, w = 0;
  while (h < H - 1 || w < W - 1) {
    if ((h == H - 1 || table.at(h + 1).at(w) == '.' )&& (w == W - 1 ||
        table.at(h).at(w + 1) == '.')) {
      cout << "Impossible" << endl;
      return 0;
    } else if (h < H - 1 && table.at(h + 1).at(w) == '#') {
      h++;
      continue;
    } else if (w < W - 1 && table.at(h).at(w + 1) == '#') {
      w++;
      continue;
    }
    cout << "error" << endl;
    return 1;
  }

  cout << "Possible" << endl;
  return 0;
}