#include <bits/stdc++.h>
using namespace std;

multiset<int> m;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    auto it = m.lower_bound(t);
    if (it != m.begin()) {
      it--;
      m.erase(it);
    }
    m.insert(t);
  }
  cout << m.size() << endl;
}