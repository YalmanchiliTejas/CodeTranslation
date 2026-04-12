#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  C *= 2;
  int ans = INT_MAX;
  for (int i = 0; i <= max(X, Y); i++) {
    int tmp = C * i;
    if (i < X) tmp += (X - i) * A;
    if (i < Y) tmp += (Y - i) * B;
    ans = min(ans, tmp);
  }
  cout << ans << "\n";
}