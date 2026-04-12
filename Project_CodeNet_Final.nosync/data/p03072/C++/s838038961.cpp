#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int n;
vector<int> h;

int solve() {
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    if (h[i - 1] > h[i])
      continue;
    bool flg = true;
    for (int k = 0; k < i; ++k) {
      if (h[k] > h[i]) {
        flg = false;
      }
    }
    if (flg)
      ++ans;
  }
  return ans;
}

int main() {
  cin >> n;
  REP(i, n) {
    int a;
    cin >> a;
    h.push_back(a);
  }
  cout << solve() << endl;
}
