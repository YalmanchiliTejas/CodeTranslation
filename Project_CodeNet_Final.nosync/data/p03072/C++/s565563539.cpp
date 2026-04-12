#include <bits/stdc++.h>
using namespace std;
const int inf = (1 << 30) - 1;

int main()
{
  int N; cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H[i];

  int ans = 0, max = -1;
  for (int i = 0; i < N; i++) {
    if (H[i] >= max) {
      ans++;
      max = H[i];
    }
  }
  cout << ans << endl;
  return 0;
}