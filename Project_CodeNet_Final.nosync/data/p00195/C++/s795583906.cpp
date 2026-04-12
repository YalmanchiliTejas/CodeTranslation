#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  int a, b;
  while (cin >> a >> b, a) {
    int cnt[5] = {};
    cnt[0] = a + b;
    for (int i = 1; i < 5; i++) {
      cin >> a >> b;
      cnt[i] = a + b;
    }
    auto p = max_element(cnt, cnt + 5);
    cout << char('A' + (p - cnt)) << " " << *p << endl;
  }

  return 0;
}
