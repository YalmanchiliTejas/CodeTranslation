#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x;
  cin >> x;

  string ans;
  if (x == 3 || x == 5 || x == 7) {
    ans = "YES";
  } else {
    ans = "NO";
  }
  cout << ans << endl;

  return 0;
}
