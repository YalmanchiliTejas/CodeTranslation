#include <bits/stdc++.h>
#define int long long
#define boost() ios_base :: sync_with_stdio(0); cin.tie(); cout.tie(); cout << fixed; cout << setprecision(15); srand(time(NULL))
#define all(x) x.begin(), x.end()
using namespace std;

int n;
int h[33];

signed main () {
  cin >> n;
  int cur = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    if (h[i] >= cur) res += 1;
    cur = max (h[i], cur);
  }
  cout << res << endl;
  return 0;
}

