#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      ans++;
      continue;
    }

    bool flag = true;
    for (int j = 0; j < i; j++) if (H[j] > H[i]) flag = false;
    if (flag) ans++;
  }
  cout << ans << endl;
}