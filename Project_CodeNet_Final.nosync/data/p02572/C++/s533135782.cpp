#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main (void) {
  int n; cin >> n;
  int64_t sum = 0;
  vector<int> a(n); for (int& ai: a) cin >> ai;
  vector<int64_t> suffix(n);
  for (int64_t i = n - 1, sufsum = 0;i >= 0;i--) {
    sufsum = (sufsum + a[i]) % MOD;
    suffix[i] = sufsum;
  }
  for (int i = 0;i < n - 1;i++) {
    sum = (sum + (a[i] * suffix[i + 1]) % MOD) % MOD;
  }

  cout << sum << '\n';
}