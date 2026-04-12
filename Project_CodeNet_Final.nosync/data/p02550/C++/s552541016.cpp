#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U> void cmax(T &a, U b) { if (a < b) a = b; }
template<typename T, typename U> void cmin(T &a, U b) { if (a > b) a = b; }

signed main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  long N, X, M;
  cin >> N >> X >> M;

  long now = 0, ans = 0;
  vector<bool> used(M);
  vector<long> hist {-1};

  auto update = [&](long n) {
    now++;
    ans += n;
    used.at(n) = true;
    hist.push_back(n);
  };

  update(X);

  while (now < N) {
    long next = X * X % M;
    if (used.at(next)) break;
    X = next;
    update(X);
  }

  if (now == N) return cout << ans << "\n", 0;

  long x = find(hist.begin(), hist.end(), X * X % M) - hist.begin();
  long len = now - x + 1;
  long sum = accumulate(hist.begin() + x, hist.begin() + x + len, 0L);
  long rem = N - now;

  ans += rem / len * sum;
  ans += accumulate(hist.begin() + x, hist.begin() + x + rem % len, 0L);
  cout << ans << "\n";
}