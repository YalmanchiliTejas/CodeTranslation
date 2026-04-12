#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  deque<int> d;
  rep(i,n) {
    auto p = lower_bound(d.begin(), d.end(), a[i]);
    int index = p - d.begin();
    if (index == 0) {
      d.push_front(a[i]);
    } else d[index-1] = a[i];
  }
  int ans = d.size();
  cout << ans << endl;
  return 0;
}
