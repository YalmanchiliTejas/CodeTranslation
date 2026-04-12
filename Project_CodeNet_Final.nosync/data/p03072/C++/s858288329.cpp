#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int *H = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }
  int cnt = 1;
  for (int i = 1; i < N; i++) {
    bool flag = true;
    for (int j = 0; j <= i - 1; j++) {
      if (H[j] > H[i]) {
        flag = false;
        break;
      }
    }
    if (flag) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}