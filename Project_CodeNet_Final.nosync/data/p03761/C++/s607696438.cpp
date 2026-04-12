#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
constexpr int INF = 0x3f3f3f3f;
int main() {
  int n;
  cin >> n;

  vector<int> cnt(26, INF);
  rep(i, 0, n) {
    string s;
    cin >> s;
    vector<int> tmp(26);
    for (char c : s) tmp[c - 'a']++;
    rep(i, 0, 26) { cnt[i] = min(cnt[i], tmp[i]); }
  }

  string ans = "";
  rep(i, 0, 26) { rep(j, 0, cnt[i]) ans += (char)(i + 'a'); }
  cout << ans << endl;
  return 0;
}
