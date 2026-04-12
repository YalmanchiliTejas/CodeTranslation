#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  deque<ll> colors;
  for (ll i = 0; i < n; i++) {
    auto it = lower_bound(colors.begin(), colors.end(), a[i]);
    if (it == colors.begin()) {
      colors.push_front(a[i]);
    } else {
      *(it - 1) = a[i];
    }
  }

  cout << colors.size() << endl;
}
