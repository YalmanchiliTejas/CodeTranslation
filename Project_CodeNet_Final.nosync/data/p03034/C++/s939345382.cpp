#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  long long maxscore = 0;
  for (int c = 1; c <= n-1; ++c) {
    // k=0 =>  0 -> n-1
    // k=1 =>  0 -> n-1-c  -> c -> n-1
    // k=2 =>  0 -> n-1-2c -> c -> n-1-c -> 2c -> n-1
    long long score = 0;
    for (int k = 1; c*k < n-1; ++k) {
      //    n-1-c*k == c*s
      // or n-1-c*s == c*k
      int l = n-1-c*k, r = c*k;
      if (l % c == 0 && l/c <= k) break;
      if ((n-1-r) % c == 0 && (n-1-r)/c <= k) break;
      if (l <= c) break;
      score += s[l] + s[r];
      maxscore = max(maxscore, score);
    }
  }
  cout << maxscore << endl;
}