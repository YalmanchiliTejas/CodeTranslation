
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <deque>
#include <functional>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <string>
#include <vector>
#include <vector>

using namespace std;

#define int long long

#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

#define debug(x) cerr << #x << ": " << x << endl;

const int MOD = 1e9 + 7;

signed main(void)
{
  int num;

  int n; cin >> n;
  vector<vector<int>> c(n);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    c[i] = vector<int>(26);
    for (auto it = s.cbegin(); it != s.cend(); ++it) {
      ++c[i][(*it) - 'a'];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      c[0][j] = min(c[0][j], c[i][j]);
    }
  }

  string t = "";
  for (int i = 0; i < 26; ++i) {
    if (c[0][i] == 0) continue;
    for (int j = 0; j < c[0][i]; ++j) {
      t += i + 'a';
    }
  }
  
  cout << t << endl;
  
}
