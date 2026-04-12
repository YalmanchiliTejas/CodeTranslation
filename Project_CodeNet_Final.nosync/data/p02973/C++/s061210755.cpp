#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  multiset<int> b;
  for(int i=0;i<n;i++) cin >> a[i];
  
  for(int i=0;i<n;i++) {
    b.insert(a[i]);
    auto itr=b.begin();
    if(*itr!=a[i]) {
      itr=b.lower_bound(a[i]);
      itr--;
      b.erase(itr);
    }
  }
  cout << b.size() << endl;
}