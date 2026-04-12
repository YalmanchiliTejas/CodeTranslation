#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if (A + B < 2 * C) {
    cout << X * A + Y * B << endl;
  } else {
    ll comb_cnt_min = min(X, Y);
    ll comb_cnt_max = max(X, Y);
    X = X - comb_cnt_min;
    Y = Y - comb_cnt_min;
    cout << min(X * A + Y * B + 2 * C * comb_cnt_min, 2 * comb_cnt_max * C)
         << endl;
  }
  return 0;
}