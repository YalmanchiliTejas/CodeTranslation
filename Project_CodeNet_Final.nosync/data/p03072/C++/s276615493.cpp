#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  int ans = 1;
  for (int i = 1; i < N; i++) {
    bool flag = true;
    for (int j = 0; j < i; j++) {
      if (H[j] > H[i]) {
        flag = false;
        break;
      }
    }
    if (flag) ans++;
  }
  cout << ans << endl;

  return 0;
}