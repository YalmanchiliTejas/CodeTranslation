#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  multiset <int> s;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    auto cur = s.lower_bound(x);
    if(cur == s.begin()) {
      s.insert(x);
    } else {
      cur--;
      s.erase(cur);
      s.insert(x);
    }
  }
  cout << s.size() << '\n';
}