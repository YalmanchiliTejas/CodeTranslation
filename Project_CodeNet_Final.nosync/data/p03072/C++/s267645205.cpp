#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int ans = 0, front_highest = 0;
  rep(i, 0, n) {
    int h;
    cin >> h;
    if (h >= front_highest) {
      ans++;
      front_highest = h;
    }
  }

  cout << ans << endl;
}
