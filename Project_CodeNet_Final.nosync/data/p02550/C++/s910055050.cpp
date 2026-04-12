#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, X, M;
  cin >> N >> X >> M;

  long ans = 0, now = 0;
  vector<bool> used(M);
  vector<long> hist {-1};

  while (now < N) {
    if (used.at(X)) break;
    else now++;
    ans += X;
    used.at(X) = true;
    hist.push_back(X);
    X = X * X % M;
  }

  if (now == N) return cout << ans << "\n", 0;

  long x = -1;
  for (long i = 0; i < (long) hist.size(); i++) {
    if (hist.at(i) == X) x = i;
  }

  long rem = N - now;
  long len = now - x + 1;
  long sum = 0;
  for (long i = x; i <= now; i++) sum += hist.at(i);

  ans += rem / len * sum;
  rem %= len;

  for (long i = x; rem--; i++) ans += hist.at(i);
  cout << ans << "\n";
}