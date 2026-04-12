#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, highest = 0, cnt = 0; cin >> N;
  for (int i = 0; i < N; i++) {
    int h; cin >> h;
    if (h >= highest) {
      cnt++;
      highest = h;
    }
  }
  cout << cnt << endl;
  return 0;
}
