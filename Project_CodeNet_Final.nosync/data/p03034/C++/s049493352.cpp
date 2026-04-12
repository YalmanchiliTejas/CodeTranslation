#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int s[N];
  for (int i = 0; i < N; i++) cin >> s[i];

  long long ans = 0;
  int passed[N] = {};
  for (int c = 1; c < N; c++) {
    long long point = 0;
    for (int k = 0; k < N; k++) {
      int s1 = N - 1 - k * c;
      int s2 = k * c;

      if (s1 == s2) break;
      if ((k + 1) * c >= N - 1) break;
      if (passed[s1] == c) break;
      if (passed[s2] == c) break;

      point += s[s1] + s[s2];
      ans = max(ans, point);

      passed[s1] = passed[s2] = c;
    }
  }

  cout << ans << endl;

  return 0;
}
