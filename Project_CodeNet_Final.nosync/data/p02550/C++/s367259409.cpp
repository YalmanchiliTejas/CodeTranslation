#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, x, m;
  cin >> n >> x >> m;
  vector<int> app(m, -1);
  vector<long long> loop;
  long long now = x;
  for (long long i = 0; 0 > app[now]; i++, now = now * now % m) {
    app[now] = i;
    loop.emplace_back(now);
  }
  if (app[now] > n) {
    cout << accumulate(begin(loop), begin(loop) + n, 0ll) << endl;
  } else {
    auto ans = accumulate(begin(loop), begin(loop) + app[now], 0ll);
    n -= app[now];
    int len = size(loop) - app[now];
    ans += accumulate(begin(loop) + app[now], end(loop), 0ll) * (n / len);
    ans += accumulate(begin(loop) + app[now], begin(loop) + app[now] + n % len,
                      0ll);
    cout << ans << endl;
  }
}
