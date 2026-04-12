#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  rep(i, N) cin >> H[i];
  int ans = 1;
  for (int i = 1; i < N; i++) {
    bool can = true;
    for (int j = 0; j < i; j++) {
      if (H[i] < H[j]) {
        can = false;
        break;
      }
    }
    if(can) ans++;
  }
  cout << ans << endl;
}