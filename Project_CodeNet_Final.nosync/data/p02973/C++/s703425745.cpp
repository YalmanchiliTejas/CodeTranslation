#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] *= -1;
  }
  vector<int> dp(n + 1, INF);
  for (int i = 0; i < n; i++) {
    *upper_bound(begin(dp), end(dp), a[i]) = a[i];
  }
  cout << lower_bound(begin(dp), end(dp), INF) - begin(dp) << endl;
}
