#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> H(N);
  for (int i = 0; i < N; ++i) {
    cin >> H.at(i);
  }

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans++;
    for (int j = 0; j < i; ++j) {
      if (H.at(i) < H.at(j)) {
        ans--;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
