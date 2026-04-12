#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < (n); i++)

using namespace std;

void solve() {
  long N;
  cin >> N;
  string ret;
  rep (i, N) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (i == 0) {
      ret = s;
      continue;
    }
    long x = 0;
    long y = 0;
    vector<char> cvec;
    while (x < ret.size() and y < s.size()) {
      if (ret[x] == s[y]) {
        cvec.push_back(ret[x]);
        x++;
        y++;
      } else if (ret[x] < s[y]) x++;
      else if (ret[x] > s[y]) y++;
    }
    ret = string(cvec.begin(), cvec.end());
  }
  cout << ret << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
