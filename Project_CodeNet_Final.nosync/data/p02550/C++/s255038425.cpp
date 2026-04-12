#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll f(ll x, ll m) {
  return x % m;
}

int main() {
  ll n, x, m;
  cin >> n >> x >> m;

  bool flag = false;
  vector<pair<ll,ll>> selected(1e5, make_pair(-1, 0));
  ll vsum = x;
  ll a1 = x;
  for (ll i = 2; i <= n;) {
    ll a2 = f(a1*a1, m);
    if (selected[a2].first != -1 && flag == false) {
      ll f = selected[a2].first;
      ll s = selected[a2].second;
      ll dsum = vsum - s + a2;
      vsum = s + dsum * ((n - f) / (i - f));
      a1 = a2;
      i = f + (n - f) / (i - f) * (i - f) + 1;
      flag = true;
    }
    else {
      vsum += a2;
      a1 = a2;
      selected[a2] = make_pair(i, vsum);
      ++i;
    }
  }

  cout << vsum << endl;
}
