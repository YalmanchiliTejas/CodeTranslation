#include <iostream>
#include <vector>
#include <set>

typedef long long ll;
ll N, X, M;

int main() {
  std::cin >> N >> X >> M;
  std::vector<ll> xp = {X};
  std::set<ll> up = {X};
  ll x = X, r;
  while (true) {
    x = (x * x) % M;
    if (up.find(x) != up.end()) {
      r = x;
      break;
    }
    xp.push_back(x);
    up.insert(x);
  }

  int n, m;
  for (int i = 0; i < xp.size(); ++i)
    if (xp[i] == r) {
      n = i;
      m = xp.size() - n;
      break;
    }

  ll tail_sum = 0, cycle_sum = 0;
  for (int i = 0; i < n; ++i)
    tail_sum += xp[i];
  for (int i = n; i < xp.size(); ++i)
    cycle_sum += xp[i];

  ll ans;
  if (N <= n) {
    ans = 0;
    for (int i = 0; i < N; ++i)
      ans += xp[i];
  } else {
    ans = tail_sum;
    N -= n;
    ans += cycle_sum * (N / m);
    for (int i = 0; i < (N % m); ++i)
      ans += xp[i+n];
  }
  std::cout << ans << "\n";

  return 0;
}
