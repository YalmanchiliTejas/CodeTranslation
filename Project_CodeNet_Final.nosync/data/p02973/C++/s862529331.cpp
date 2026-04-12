#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  deque<int> d;
  rep(i, n) {
    int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    if (p == 0)
      d.push_front(a[i]);
    else
      d[p - 1] = a[i];
  }

  cout << d.size() << endl;
  return 0;
}
