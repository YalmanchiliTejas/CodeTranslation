#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v) do { x = max(x, v); } while (0)
#define chmin(x, v) do { x = min(x, v); } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  set<char> se;
  string s;
  cin >> s;
  for (auto c : s) {
    se.insert(c);
  }
  cout << ((se.size() == 2) ? "Yes" : "No") << endl;
  return 0;
}
