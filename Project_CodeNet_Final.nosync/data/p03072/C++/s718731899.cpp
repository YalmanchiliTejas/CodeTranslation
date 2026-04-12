#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int H = 0, maxH = 0, ans = 0;
  while (N--) {
    cin >> H;
    if (H >= maxH) ans++;
    maxH = max(H, maxH);
  }

  cout << ans << endl;

  return 0;
}
