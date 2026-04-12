#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int max_high = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int high_i; cin >> high_i;
    if (high_i >= max_high) {
      max_high = high_i;
      ans++;
    }
  }
  cout << ans << endl;
}