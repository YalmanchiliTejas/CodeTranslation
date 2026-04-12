#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;

  int ans = 800 * n - 200 * (n / 15);

  cout << ans << endl;
  return 0;
}
