#include <bits/stdc++.h>

using namespace std;

void solve() {
  string a;
  cin >> a;

  cout << (a[0] == a[1] && a[1] == a[2] ? "No" : "Yes") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
