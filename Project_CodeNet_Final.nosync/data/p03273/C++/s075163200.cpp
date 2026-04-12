#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<int, int>
#define debug(x) cout << #x << ": " << x << ", "
#define debugln(x) cout << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w; cin >> h >> w;
  bool mat[h][w];

  rep(i, h) {
    string s; cin >> s;
    rep(j, w) {
      mat[i][j] = (s.at(j) == '.');
    }
  }

  vector<bool> skiph(h);
  rep(i, h) {
    skiph.at(i) = true;
    rep(j, w) {
      skiph.at(i) = skiph.at(i) && mat[i][j];
    }
  }
  vector<bool> skipw(w);
  rep(j, w) {
    skipw.at(j) = true;
    rep(i, h) {
      skipw.at(j) = skipw.at(j) && mat[i][j];
    }
  }  

  rep(i, h) {
    if (skiph.at(i)) continue;
    rep(j, w) {
      if (skipw.at(j)) continue;
      cout << (mat[i][j] ? '.' : '#');
    }
    cout << endl;
  }
}