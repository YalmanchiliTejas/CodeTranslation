#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int m, n;
  while (cin >> m >> n, m) {
    vector<int> a(m);
    iota(a.begin(), a.end(), 1);
    int curr = 0;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      if (m == 1) continue;
      string ans = "";
      if (i % 3 == 0 || i % 5 == 0) {
        if (i % 3 == 0) ans += "Fizz";
        if (i % 5 == 0) ans += "Buzz";
      } else {
        ans = to_string(i);
      }
      if (s != ans) {
        a.erase(a.begin() + curr);
        curr %= (--m);
      } else {
        curr = (curr + 1) % m;
      }
    }
    for (int i = 0; i < m; i++) {
      cout << a[i] << " \n"[i + 1 == m];
    }
  }

  return 0;
}
