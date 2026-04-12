#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<int> d;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(d.rbegin(), d.rend(), a[i]);
    if (it == d.rbegin()) {
      d.push_back(a[i]);
    } else {
      --it;
      *it = a[i];
    }
  }
  int ans = d.size();
  cout << ans << endl;
  return 0;
}