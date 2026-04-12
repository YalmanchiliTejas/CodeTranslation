#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using  namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];

  multiset<int> S;
  rep(i, n) {
    S.insert(a[i]);
    auto itr = S.find(a[i]);
    if (itr != S.begin()) S.erase(--itr);
  }
  cout << S.size() << endl;
  return 0;
}