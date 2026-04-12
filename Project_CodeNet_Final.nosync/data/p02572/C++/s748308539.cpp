#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;

int main() {
  int n;
  cin >> n;
  long long ans = 0, tot = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans = (ans + tot * a) % mod;
    tot = (tot + a) % mod;
  }
  cout << ans << endl;
  return 0;
}