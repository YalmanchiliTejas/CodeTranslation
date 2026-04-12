#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = int(1e5 + 5);
const int mod = int(1e9 + 7);
const double eps = 1e-9;
const double pi = 3.1415926535897932384626433832795;

multiset<int> s;

void solve() {
  s.insert(-1);
  int n; scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    auto j = s.lower_bound(x);
    if (j != s.begin()) {
      j--; s.erase(j);
    }
    s.insert(x);
  }
  printf("%d\n", s.size());
}

int main() {
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  int tests = 1;
  //scanf("%d", &tests);
  while (tests--) {
    solve();
  }
  return 0;
}
