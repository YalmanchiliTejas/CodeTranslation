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
  
  vector<vector<ll>> memo(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    if (n % 2 == 1) memo.at(i).at(i) = a.at(i);
    else memo.at(i).at(i) = -a.at(i);
  }
  
  for (int width = 2; width <= n; width++) {
    for (int i = 0; i + width <= n; i++) {
      int l = i, r = i + width - 1;
      if ((n - width) % 2 == 1) {
        memo.at(l).at(r) = min(memo.at(l).at(r - 1) - a.at(r), memo.at(l + 1).at(r) - a.at(l));
      }
      else {
        memo.at(l).at(r) = max(memo.at(l).at(r - 1) + a.at(r), memo.at(l + 1).at(r) + a.at(l));
      }
    }
  }
  
  cout << memo.at(0).at(n - 1) << '\n';
}