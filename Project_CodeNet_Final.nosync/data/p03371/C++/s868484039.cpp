// Last Change: 03/22/2019 21:12:03.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

/*
AB全てABで
AはABで、BはBで
AはAで、BはABで
AはAで、BはBで、
*/

int main() {
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  ll ans, tmp;

  // AはABで
  tmp = C * max(X, Y) * 2;
  ans = tmp;

  // AはABで,BはBで
  tmp = C * X * 2;
  if (X < Y) {
    tmp += B * (Y - X);
  }
  ans = min(ans, tmp);

  // AはAで,BはABで
  tmp = C * Y * 2;
  if (X > Y) {
    tmp += A * (X - Y);
  }
  ans = min(ans, tmp);

  // AはAで,BはBで
  tmp = A * X + B * Y;
  ans = min(ans, tmp);

  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}
