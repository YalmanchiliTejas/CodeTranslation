#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int ans = 1e9;

  for (int i = 0; i <= 100000; i++) {
    ans = min(ans, i * C * 2 + max(0, X - i) * A + max(0, Y - i) * B);
  }

  cout << ans << "\n";
}