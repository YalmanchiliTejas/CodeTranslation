#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string X; cin >> X;
  string ans = "Yes";
  if (X == "AAA" || X == "BBB") ans = "No";
  cout << ans << '\n';
  return 0;
}