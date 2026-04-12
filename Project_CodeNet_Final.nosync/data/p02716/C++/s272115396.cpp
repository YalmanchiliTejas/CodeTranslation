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
  
  ll ans = -1e18;
  if (n % 2 == 1) {
    vector<ll> left(n / 2 + 2), middle(n / 2 + 2), right(n / 2 + 2);
    for (int i = 0; i < n / 2; i++) {
      left.at(i + 1) = left.at(i) + a.at(i * 2);
      middle.at(i + 1) = middle.at(i) + a.at(i * 2 + 1);
    }
    for (int i = n / 2; i > 0; i--) {
      right.at(i) = right.at(i + 1) + a.at(i * 2);
    }
    vector<ll> best(n / 2 + 2);
    best.at(0) = 0;
    for (int i = 1; i <= n / 2; i++) {
      best.at(i) = max(best.at(i - 1) + middle.at(i) - middle.at(i - 1), left.at(i));
    }
    for (int i = 0; i <= n / 2; i++) {
      ans = max(ans, best.at(i) + right.at(i + 1));
    }
  }
  else {
    ll keep = 0;
    for (int i = 1; i < n; i += 2) keep += a.at(i);
    ans = keep;
    for (int i = 1; i < n; i += 2) {
      keep = keep - a.at(i) + a.at(i - 1);
      ans = max(ans, keep);
    }
  }
  
  cout << ans << '\n';
}