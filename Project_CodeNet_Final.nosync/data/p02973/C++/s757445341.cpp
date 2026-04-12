#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n;
  cin >> n;

  multiset<int> s;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    if (s.size() == 0) s.insert(x);
    else {
      auto j = s.lower_bound(x);
      if (j == s.begin()) s.insert(x);
      else {
        --j;
        s.erase(j);
        s.insert(x);
      }
    }
  }

  cout << s.size() << '\n';
}
