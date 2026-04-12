#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio (0);
  cin.tie (0);
  ll n;
  cin >> n;
  vector<ll>a (n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<ll>s;
  s.insert (a[0]);
  for (ll i = 1; i < n; i++) {
    auto it = s.lower_bound (a[i]);
    if (it != s.begin() ) {
      it--;
      s.erase (it);
    }
    s.insert (a[i]);
  }
  cout << (ll) s.size() << '\n';
  return 0;

}
