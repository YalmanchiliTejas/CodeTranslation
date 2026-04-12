#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; ++i) cin >> H[i];
  int ans = 1;
  int maxH = H[0];
  for (int i = 1; i < N; ++i) {
    if (H[i] >= maxH) {
      ans++;
      maxH = H[i];
    }
  }
  cout << ans << endl;
  return 0;
}

