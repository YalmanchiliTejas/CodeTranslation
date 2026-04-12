#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int H[30];
  for (int i = 0; i < N; i++) cin >> H[i];

  int ans = 1;
  int maxh = H[0];
  for (int i = 1; i < N; i++) {
    if (H[i] >= maxh) {
      maxh = H[i];
      ans++;
    }
  }

  cout << ans << endl;
}