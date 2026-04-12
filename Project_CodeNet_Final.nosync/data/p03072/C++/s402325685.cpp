#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> H(N);
  rep(i, N) cin >> H[i];

  int ans = 0;
  rep(i, N) {
    int cnt = 0;
    rep(j, i) {
      if (H[i] >= H[j])
        cnt++;
    }
    if (cnt == i)
      ans++;
  }

  cout << ans << endl;
}