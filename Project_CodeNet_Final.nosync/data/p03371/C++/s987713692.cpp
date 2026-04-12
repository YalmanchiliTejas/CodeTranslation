#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  long long ans = 1001001001;
  for (int i = 0; i <= 100000; i++) {
    long long res = 2 * C * i + max(X - i, 0) * A + max(Y - i, 0) * B;
    ans = min(ans, res);
  }

  cout << ans << endl;
}