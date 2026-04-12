#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()

bool check(int i, int j, int h, int w, const vector<string>& field) {
  if (field[i][j] == '.') return true;
  if (i > 0 && field[i - 1][j] == '#') return true;
  if (i < h - 1 && field[i + 1][j] == '#') return true;
  if (j > 0 && field[i][j - 1] == '#') return true;
  if (j < w - 1 && field[i][j + 1] == '#') return true;
  return false;
}

int main() {
  //
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if (a + b <= 2 * c) {
    cout << a * x + b * y << endl;
  } else {
    if (x >= y) {
      cout << min(2 * c * x, 2 * c * y + a * (x - y)) << endl;
    } else {
      cout << min(2 * c * y, 2 * c * x + b * (y - x)) << endl;
    }
  }
  return 0;
}
