#include <bits/stdc++.h>

#define stirng string
#define vvi vector<vector<int>>
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int inf = 1e9 + 7;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int ans = 0;
  int i = 1;
  while ((x - z) >= (y + z) * i) {
    ans++;
    i++;
  }
  cout << ans << endl;
  return 0;
}
