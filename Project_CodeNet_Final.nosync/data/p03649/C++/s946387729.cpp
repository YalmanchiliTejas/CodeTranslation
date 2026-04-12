#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  ll ans = 0;
  while (true) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a.at(i) >= n) flag = false;
    }
    if (flag) break;
    
    vector<ll> keep(n);
    ll count = 0;
    for (int i = 0; i < n; i++) {
      count += a.at(i) / n;
      keep.at(i) = a.at(i) / n;
      a.at(i) %= n;
    }
    for (int i = 0; i < n; i++) {
      a.at(i) += count - keep.at(i);
    }
    ans += count;
  }
  
  cout << ans << '\n';
}