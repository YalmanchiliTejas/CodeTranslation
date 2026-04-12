#include <bits/stdc++.h>

using namespace std;
using lint = std::int_fast64_t;

vector<lint> P, BP;

lint f(lint n, lint x) {
  if (n == 0) {
    return x <= 0 ? 0 : 1;
  } else if (x <= BP[n - 1] + 1) {
    return f(n - 1, x - 1);
  } else {
    return P[n - 1] + f(n - 1, x - (BP[n - 1] + 2)) + 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  lint N, X;
  cin >> N >> X;
  P.resize(N + 1), BP.resize(N + 1);
  P[0] = 1, BP[0] = 1;
  for (int i = 1; i <= N; i++) {
    P[i] = 2 * P[i - 1] + 1;
    BP[i] = 2 * BP[i - 1] + 3;
  }
  cout << f(N, X) << '\n';
  return 0;
}
