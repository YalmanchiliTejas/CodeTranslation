#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  string S, ans;
  cin >> N >> S >> K;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == S.at(K - 1)) {
      ans += S.at(K - 1);
    }
    else {
      ans += '*';
    }
  }
  cout << ans << endl;
  return 0;
}
