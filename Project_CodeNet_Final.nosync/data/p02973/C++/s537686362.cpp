#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  multiset<int> s;
  for(int i=0;i<n;i++) {
    if(i == 0) s.emplace(a[i]);
    else {
      auto it = s.lower_bound(a[i]);
      if(it == s.begin()) s.emplace(a[i]);
      else {
        s.erase(prev(it));
        s.emplace(a[i]);
      }
    }
  }
  cout << s.size() << endl;
}
