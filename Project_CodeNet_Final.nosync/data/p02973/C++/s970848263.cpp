#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  deque<int> d;  
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    int idx = lower_bound(d.begin(), d.end(), a) - d.begin();
    if (idx == 0) {
      d.push_front(a);
    } else {
      d[idx - 1] = a;
    }
  }
  cout << d.size() << endl;
  return 0;
}

