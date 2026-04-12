#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef pair<ul, ul> P;
map<int, int> dp;
#define REP(i, n) for (int i = 0; i < n; i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> H(N, 0);
  REP(ii, N) cin >> H[ii];
  int max_height = 0;
  int ans = 0;
  REP(ii, N) {
    if (max_height <= H[ii]) {
      ++ans;
      max_height = H[ii];
    }
  }
  cout << ans << endl;
  return 0;
}
