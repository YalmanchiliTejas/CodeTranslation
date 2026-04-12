#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int x;
  cin >> x;

  string ans;
  if (x == 7 || x == 5 || x == 3) {
    ans = "YES";
  } else {
    ans = "NO";
  }

  cout << ans << endl;
  return 0;
}
