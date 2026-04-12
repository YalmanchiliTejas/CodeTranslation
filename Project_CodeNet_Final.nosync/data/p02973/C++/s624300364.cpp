#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;

  multiset<int> s;
  for (int i=0; i<n; i++) {
    int a;
    cin>>a;
    if (i == 0) {
      s.insert(a);
      continue;
    }
    auto it = s.lower_bound(a);
    if (it == s.begin()) {
      s.insert(a);
    } else {
      --it;
      s.erase(it);
      s.insert(a);
    }
  }

  cout<<s.size()<<endl;
}