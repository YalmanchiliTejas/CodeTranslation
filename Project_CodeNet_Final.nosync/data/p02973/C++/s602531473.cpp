#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  map<int, vector<int>> m;
  for (int i=0; i<n; i++) {
    int a;
    cin>>a;
    m[a].push_back(i);
  }
  set<int> s;
  for (auto e: m) {
    set<int> t;
    for (int idx: e.second) {
      if (s.empty()) {
        t.insert(idx);
        continue;
      }
      auto it = s.upper_bound(idx);
      if (it == s.begin()) {
        t.insert(idx);
      } else {
        --it;
        s.erase(it);
        t.insert(idx);
      }
    }
    for (int i: t) {
      s.insert(i);
    }
  }
  cout<<s.size()<<endl;
}