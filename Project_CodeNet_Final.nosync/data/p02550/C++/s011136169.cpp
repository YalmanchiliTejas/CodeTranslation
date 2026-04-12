#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ll n, x, m;
  cin >> n >> x >> m;
  vector<ll> loop;
  set<ll> see;
  ll now = x;
  while (true) {
    if (see.count(now)) {
      break;
    } else {
      see.insert(now);
      loop.push_back(now);
      now = (now * now) % m;
    }
  }
  if (loop.size() >= n) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans += loop[i];
    }
    cout << ans << endl;
  } else {
    int idx = -1;
    ll ans = 0;
    ll loopsum = 0;
    ll loopcnt = 0;
    for (int i = 0; i < loop.size(); i++) {
      if (loop[i] == now) {
        idx = i;
      }
      if (idx == -1) {
        ans += loop[i];
      } else {
        loopsum += loop[i];
        loopcnt += 1;
      }
    }
    ans += (n - idx) / loopcnt * loopsum;
    for (int i = 0; i < (n - idx) % loopcnt; i++) {
      ans += loop[i + idx];
    }
    cout << ans << endl;
  }
}
