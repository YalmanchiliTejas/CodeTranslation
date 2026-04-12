#include <bits/stdc++.h>

using namespace std;

int main(void) {
  /* y = (A-B)*x 
   * y = (A-B)*x + b */

  int N; cin >> N;
  long long s[N];
  for (int i = 0; i < N; i++) cin >> s[i];

  long long ans = 0;
  for (int i = 1; i < N-1; i++) {
    long long f = 0;

    for (int j = i, k = N-1-i; k > i; j += i, k -= i) {
      if ((N-1) % i == 0 && j >= k) break;

      f += s[j] + s[k];
      ans = max(ans, f);
    }
  }

  cout << ans << endl;
  return 0;
}