#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H;
  cin >> N;

  int maxH = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> H;
    if (maxH <= H) ans++;
    maxH = max(maxH, H);
  }

  cout << ans << endl;

  return 0;
}
