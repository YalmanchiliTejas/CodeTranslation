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
  map<int, int> x;

  rep(i, 0, n) {
    int a;
    cin >> a;
    if (x.size() == 0)
      x[a]++;
    else {
      auto v = x.lower_bound(a);
      if (v != x.begin()) {
        v--;
        if (x[(*v).first] > 1)
          x[(*v).first]--;
        else
          x.erase(v);
      }
      x[a]++;
    }
  }

  int ans = 0;
  for (auto xx : x)
    ans += xx.second;

  cout << ans << endl;
}
