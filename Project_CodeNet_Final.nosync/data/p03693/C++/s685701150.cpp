#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int r, g, b, ans;
  cin >> r >> g >> b;
  ans = 100 * r + 10 * g + b;

  cout << (ans % 4 == 0 ? "YES" : "NO") << endl;
  return 0;
}
