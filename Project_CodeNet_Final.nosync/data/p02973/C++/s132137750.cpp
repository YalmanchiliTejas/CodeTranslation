#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  deque<int> d;
  for (int i{}; i < N; ++i) {
    int a;
    cin >> a;
    int p = lower_bound(d.begin(), d.end(), a) - d.begin();
    if (!p) {
      d.push_front(a);
    } else {
      d[p-1] = a;
    }
  }

  cout << d.size() << endl;
  return 0;
}
