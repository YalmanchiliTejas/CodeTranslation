#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll X; cin >> X;
  string ans = "No";
  if (X >= 30) ans = "Yes";
  cout << ans << '\n';
  return 0;
}