#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;

  map<int, int> m;
  for (int i=0; i<n; i++) {
    int a;
    cin>>a;
    if (i == 0) {
      ++m[a];
      continue;
    }
    auto it = m.lower_bound(a);
    if (it == m.end()) {
      --it;
      int k = (*it).first;
      --m[k];
      if (m[k] == 0) {
        m.erase(k);
      }
      ++m[a];
    } else if (it == m.begin()) {
      ++m[a];
    } else {
      --it;
      int k = (*it).first;
      --m[k];
      if (m[k] == 0) {
        m.erase(k);
      }
      ++m[a];
    }
  }

  int cnt = 0;
  for (auto mi: m) {
    cnt += mi.second;
  }
  cout<<cnt<<endl;
}