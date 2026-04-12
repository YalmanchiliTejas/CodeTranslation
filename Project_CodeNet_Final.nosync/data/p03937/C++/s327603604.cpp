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
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

void solve() {
  long H, W;
  cin >> H >> W;
  long foo = 0;
  rep (i, H) {
    string A;
    cin >> A;
    rep (j, W) if (A[j] == '#') foo++;
  }
  if (foo == H + W - 1) puts("Possible");
  else puts("Impossible");
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
