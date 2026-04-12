/**
 *    author:  tourist
 *    created: 21.12.2019 21:42:49       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s.push_back(x);
    while (s.size() >= 3 && s[s.size() - 2] > s.back() && s[s.size() - 2] > s[s.size() - 3]) {
      s[s.size() - 3] = s[s.size() - 3] - s[s.size() - 2] + s.back();
      s.pop_back();
      s.pop_back();
    }
  }
  long long ans = 0;
  int i = 0, j = (int) s.size() - 1;
  int f = 1;
  while (i <= j) {
    ans += f * (s[i] > s[j] ? s[i++] : s[j--]);
    f = -f;
  }
  cout << ans << '\n';
  return 0;
}
