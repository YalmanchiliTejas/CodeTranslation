#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cur;
  cin >> n;
  int maxi = -1, ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> cur;
    if (cur >= maxi) ans++;
    maxi = max(maxi, cur);
  }
  cout << ans;
}