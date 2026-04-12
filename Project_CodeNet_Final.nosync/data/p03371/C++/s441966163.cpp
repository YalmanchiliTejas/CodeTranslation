#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  long long ans = LONG_LONG_MAX;
  for (int i = 0; i < 1e5 + 1; i++) {
    ans = min(C * i * 2 + A * max(0LL, X - i) + B * max(0LL, Y - i), ans);
  }
  cout << ans << endl;
  return 0;
}