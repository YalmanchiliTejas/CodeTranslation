#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  deque<int> a;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (i & 1) {
      a.push_front(t);
    } else {
      a.push_back(t);
    }
  }
  if (n & 1) {
    reverse(a.begin(), a.end());
  }
  for (auto x : a) {
    cout << x << " ";
  }
  return 0;
}
