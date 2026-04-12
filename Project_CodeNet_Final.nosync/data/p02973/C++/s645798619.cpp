#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  multiset<int> s;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    auto it = s.lower_bound(x);
    if (it != s.begin()) {
      --it;
      s.erase(it);
    }
    s.insert(x);
  }
  printf("%d\n", int(s.size()));
  return 0;
}

