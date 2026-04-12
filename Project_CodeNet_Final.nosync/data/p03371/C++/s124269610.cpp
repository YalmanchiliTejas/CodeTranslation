#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll ans = 0;
  if (2 * C > A + B) {
    ans += A * X + B * Y;
  } else {
    ll minVal = min(X, Y);
    ans += minVal * 2 * C;
    X -= minVal;
    Y -= minVal;
    if (X == 0) {
      if (B > 2 * C)
        ans += 2 * C * Y;
      else
        ans += B * Y;
    } else {
      if (A > 2 * C)
        ans += 2 * C * X;
      else
        ans += A * X;
    }
  }

  cout << ans << endl;

  return 0;
}
