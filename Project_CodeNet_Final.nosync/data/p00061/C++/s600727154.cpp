#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int p, s;
  char c;
  vector<pii> v;
  while (cin >> p >> c >> s, p) {
    v.emplace_back(p, s);
  }
  sort(v.begin(), v.end(), [&](pii a, pii b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
  });
  int q;
  while (cin >> q) {
    int last = 1 << 30, ans = 0;
    for (auto i : v) {
      if (i.second != last) {
        last = i.second;
        ans++;
      }
      if (i.first == q) {
        cout << ans << endl;
        break;
      }
    }
  }

  return 0;
}
