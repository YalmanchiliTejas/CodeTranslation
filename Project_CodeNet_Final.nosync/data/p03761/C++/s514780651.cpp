#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

string solve(vector<string>& sv, int n) {
  string ret;
  vector<vector<int>> v(50, vector<int>(256));
  REP(i, n) {
    for (auto c : sv[i])
      ++v[i][c - '0'];
  }
  for (char c = 'a'; islower(c); ++c) {
    int cnt = (1 << 30);
    REP(i, n)
      cnt = min(cnt, v[i][c - '0']);
    for (int i = 0; i < cnt; ++i)
      ret += c;
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  vector<string> v(n);
  REP(i, n) cin >> v[i];
  cout << solve(v, n) << endl;
}
