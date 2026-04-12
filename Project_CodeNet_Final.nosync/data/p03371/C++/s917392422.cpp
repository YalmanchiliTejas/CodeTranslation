#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  LL A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  LL Z = max(X, Y);
  LL vmin = LLONG_MAX;
  for (LL i = 0; i <= Z; ++i) {
    LL cost = 2LL * i * C;
    if (X - i > 0) cost += A * (X-i);
    if (Y - i > 0) cost += B * (Y-i);
    vmin = min<LL>(vmin, cost);
  }
  cout << vmin << endl;
}
