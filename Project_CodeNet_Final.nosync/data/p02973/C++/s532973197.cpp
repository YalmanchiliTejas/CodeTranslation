#include <iostream>
#include <deque>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  deque<int> dq;
  rep(i, n) {
    int itr = lower_bound(dq.begin(), dq.end(), a[i]) - dq.begin();
    if(itr == 0) dq.push_front(a[i]);
    else dq[itr-1] = a[i];
  }

  cout << dq.size() << '\n';
  return 0;
}
