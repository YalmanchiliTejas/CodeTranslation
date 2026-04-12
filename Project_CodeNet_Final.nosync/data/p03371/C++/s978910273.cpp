#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
const int INT_INF = 500000000;
const long long LONG_LONG_INF = (long long)pow(10, 18);
const int MOD = pow(10, 9) + 7;
/* contest template */
int A, B, C, X, Y;
int ans;

int main() {
  cin >> A >> B >> C >> X >> Y;
  if (C * 2 >= A + B) {
    ans = X * A + Y * B;
  } else {
    if (X >= Y) {
      ans += C * 2 * Y;
      if (C * 2 < A) {
        ans += C * 2 * (X - Y);
      } else {
        ans += A * (X - Y);
      }
    } else {
      ans += C * 2 * X;
      if (C * 2 < B) {
        ans += C * 2 * (Y - X);
      } else {
        ans += B * (Y - X);
      }
    }
  }
  cout << ans << endl;

  return 0;
}