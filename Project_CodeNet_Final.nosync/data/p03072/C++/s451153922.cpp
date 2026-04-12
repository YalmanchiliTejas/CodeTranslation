#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> as(n);
  for (int i = 0; i < n; i++) {
    cin >> as[i];
  }
  int ans = 0, nax = -1;
  for (int i = 0; i < n; i++) {
    ans += as[i] >= nax;
    nax = max(nax, as[i]);
  }cout << ans << endl;
}