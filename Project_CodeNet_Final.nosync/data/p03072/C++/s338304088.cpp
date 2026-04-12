#include <bits/stdc++.h>

#define stirng string
#define vvi vector<vector<int>>
#define vi vector<int>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int inf = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  int h[n];
  int ans = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    if (max <= h[i]) {
      ans++;
      max = h[i];
    }
  }
  cout << ans << endl;
  return 0;
}
