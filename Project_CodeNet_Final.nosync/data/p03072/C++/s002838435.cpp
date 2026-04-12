#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans;
  cin >> N;
  vector<int> height(N);
  for (int i = 0; i < N; i++) {
    cin >> height.at(i);
  }
  for (int i = 0; i < N; i++) {
    bool mienai = false;
    for (int j = 0; j < i; j++) {
      if (height.at(i) < height.at(j)) {
        mienai = true;
        break;
      }
    }
    if (mienai) {
      continue;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
