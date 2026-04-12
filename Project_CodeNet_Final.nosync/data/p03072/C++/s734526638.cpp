#include "bits/stdc++.h"

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for_each(begin(H), end(H), [](int &e) { cin >> e; });
  int ma = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    if (ma <= H[i]) ans++;
    ma = max(ma, H[i]);
  }
  cout << ans << endl;
}
