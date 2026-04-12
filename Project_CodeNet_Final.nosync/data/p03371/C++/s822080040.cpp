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
  C *= 2;
  LL vmin = 1e18;
  for (int i = 0; i <= max(X, Y); ++i) {
    LL v = i * C;
    if (X > i) v += (X - i) * A;
    if (Y > i) v += (Y - i) * B;
    vmin = min(v, vmin);
  }
  cout << vmin << endl;
}
