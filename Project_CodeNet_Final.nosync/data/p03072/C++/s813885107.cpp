#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;

  int ans{};
  int tallest{};
  for (int i{}; i < N; ++i) {
    int H;
    cin >> H;
    if (tallest <= H) {
      ++ans;
      tallest = H;
    }
  }

  cout << ans << endl;
  return 0;
}
