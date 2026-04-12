
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N;
  cin >> N;
  static int s[101010];
  for (int i = 0; i < N - 1; i++) cin >> s[i];

  int ans = 0;
  for (int i = 1; i < N; i++) {
    int sum = 0;
    int L = 0, R = N - 1;
    if ((N - 1) % i == 0) {
      while (L < R) {
        sum += s[L] + s[R];
        L += i;
        R -= i;
        ans = max(ans, sum);
      }
    } else {
      while (L + i < N - 1) {
        sum += s[L] + s[R];
        L += i;
        R -= i;
        ans = max(ans, sum);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
