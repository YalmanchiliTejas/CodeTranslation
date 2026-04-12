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
constexpr int kInf = 1e9;

int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  int vmin = kInf;
  for (int Z = 0; Z <= max(X, Y); ++Z) {
    int a = max(0, X - Z);
    int b = max(0, Y - Z);
    vmin = min(vmin, a * A + b * B + 2 * C * Z);
  }
  cout << vmin << endl;
}
