#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, X, M;
  cin >> N >> X >> M;

  long now = 1, ans = X;
  vector<bool> used(M);
  used.at(X) = true;
  vector<long> hist {-1, X};

  while (now < N) {
    long next = X * X % M;
    if (used.at(next)) break;
    X = next, now++;
    ans += X;
    used.at(X) = true;
    hist.push_back(X);
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