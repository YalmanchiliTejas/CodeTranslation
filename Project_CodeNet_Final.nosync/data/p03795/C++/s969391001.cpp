#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int ans = 0;

  ans = 800 * n;
  ans = ans - (n / 15) * 200;
  cout << ans << endl;

  return 0;
}
