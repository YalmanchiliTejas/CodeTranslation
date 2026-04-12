#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B, C, X, Y;

  cin >> A >> B >> C >> X >> Y;

  const size_t naive = A * X + B * Y;
  const size_t cand1 =
      X < Y ? C * 2 * X + (Y - X) * B : C * 2 * Y + (X - Y) * A;

  const auto ans = min({naive, cand1, static_cast<size_t>(C * 2 * max(X, Y))});
  cout << ans << endl;

  return 0;
}
