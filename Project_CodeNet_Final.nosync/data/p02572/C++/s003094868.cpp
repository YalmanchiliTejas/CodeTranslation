#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  long long ans = 0, tot = 0;
  for (int i : a) {
    ans = (ans + tot * i) % mod;
    tot = (tot + i) % mod;
  }
  cout << ans << endl;
  return 0;
}