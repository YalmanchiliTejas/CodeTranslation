#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }  
  vector<int> b = x;
  sort(x.begin(), x.end());
  int mid1 = (n - 1)/2;
  int mid2 = n/2;
  for (int i = 0; i < n; i++) {
    if (b[i] <= x[mid1]) cout << x[mid2] << '\n';
    else cout << x[mid1] << '\n'; 
  }
  return 0;
}