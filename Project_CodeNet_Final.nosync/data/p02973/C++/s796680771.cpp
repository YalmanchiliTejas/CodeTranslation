#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  deque<int> deq;
  rep(i, n) {
    int index = lower_bound(deq.begin(), deq.end(), a[i]) - deq.begin();
    if (index == 0) {
      deq.push_front(a[i]);
    } else {
      deq[index - 1] = a[i];
    }
  }

  cout << deq.size() << endl;
  return 0;
}