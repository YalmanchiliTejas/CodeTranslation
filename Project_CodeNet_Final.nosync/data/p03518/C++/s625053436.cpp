/**
 *    author:  tourist
 *    created: 26.11.2019 11:33:34       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  vector<int> seq;
  auto Do = [&](int k) {
    seq.push_back(k);
    for (int i = k; i < n; i++) {
      swap(p[i], p[i - k]);
    }
  };
  for (int it = 0; it < n - 1; it++) {
    Do(1);
    for (int i = 0; i < n - 1; i++) {
      if (p[n - 1] > p[0]) {
        Do(n - 1);
      }
      Do(1);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    assert(p[i] < p[i + 1]);
  }
  cout << seq.size() << '\n';
  for (int x : seq) {
    cout << x << '\n';
  }
  return 0;
}
