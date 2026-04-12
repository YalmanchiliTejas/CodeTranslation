#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int target = H.at(i);
    bool ok = true;
    for (int j = 0; j < i; j++) {
      if (target < H.at(j)) {
        ok = false;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << endl;
}
