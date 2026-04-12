#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  multiset<ll, greater<ll>> g;
  for (auto &a : va) {
    auto it = g.upper_bound(a);
    if (it != g.end()) {
      g.erase(it);
    }

    g.insert(a);
  }

  cout << g.size() << '\n';

  return 0;
}