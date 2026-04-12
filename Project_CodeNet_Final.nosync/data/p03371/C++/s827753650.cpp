#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long A, B, C, X, Y, ans;
  cin >> A >> B >> C >> X >> Y;

  long long min_num = min(X, Y);
  ans = min_num * min(2 * C, A + B) + (X - min_num) * min(2 * C, A) +
        (Y - min_num) * min(2 * C, B);

  cout << ans << endl;
}
