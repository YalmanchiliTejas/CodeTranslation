#include <bits/stdc++.h>

using namespace std;
typedef long long unsigned int ll;

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  map<ll, int> indices;
  vector<ll> mods;
  mods.push_back(x);
  int idx = -1;
  while ((ll)mods.size() < n) {
    x = (x * x) % m;
    if (x == mods[0] || indices[x] != 0) {
      idx = indices[x];
      break;
    } else {
      mods.push_back(x);
      indices[x] = mods.size() - 1;
    }
  }

  if (idx == -1) {
    ll ans = 0;
    for (int i = 0; i < mods.size(); ++i) {
      ans += mods[i];
    }
    cout << ans << '\n';
  } else {
    ll ans = 0;
    ll tmp = 0;
    for (int i = 0; i < mods.size(); ++i) {
      ans += mods[i];
      if (i >= idx) tmp += mods[i];
    }

    n -= mods.size();

    int size = mods.size() - idx;
    ll need = n / size;
    ll remain = n % size;
    ans += need * tmp;

    for (int i = idx; i < idx + remain; ++i) {
      ans += mods[i];
    }
    cout << ans << '\n';
  }
  return 0;
}

