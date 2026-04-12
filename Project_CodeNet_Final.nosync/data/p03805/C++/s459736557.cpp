#include <bits/stdc++.h>

#include <boost/range/adaptors.hpp>
#include <boost/range/irange.hpp>

using namespace std;
using namespace boost;
using namespace boost::adaptors;

main() {
  int64_t n, m;
  cin >> n >> m;

  vector<vector<int64_t>> links(n);
  for (auto _ : irange(0L, m)) {
    int64_t a, b;
    cin >> a >> b;
    --a;
    --b;
    links[a].push_back(b);
    links[b].push_back(a);
  }

  vector<vector<int64_t>> dp(1u << n, vector<int64_t>(n));
  dp[1][0] = 1;
  int64_t ans = 0;
  for (auto s : irange(1uL, 1uL << n)) {
    bitset<8> bs(s);

    for (auto i : irange(0L, n)) {
      if (!bs[i]) {
        continue;
      }

      for (auto j : links[i]) {
        if (bs[j]) {
          continue;
        }

        dp[s | (1uL << j)][j] += dp[s][i];
      }

      if (s == (1uL << n) - 1) {
        ans += dp[s][i];
      }
    }
  }

  cout << ans << endl;
}