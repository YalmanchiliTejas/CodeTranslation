#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
ll s[51] = {1};
ll p[51] = {1};

ll f(ll N, ll X) {
  if (N == 0 && X == 1) {
    return 1;
  } else if (X <= 1) {
    return 0;
  } else if (1 < X && X <= 1 + s[N - 1]) {
    return f(N - 1, X - 1);
  } else if (X == 2 + s[N - 1]) {
    return p[N - 1] + 1;
  } else if (2 + s[N - 1] < X && X <= 2 + 2 * s[N - 1]) {
    return p[N - 1] + 1 + f(N - 1, X - 2 - s[N - 1]);
  } else {
    return 2 * p[N - 1] + 1;
  }
}

int main() {
  ll N, X;
  cin >> N >> X;

  for (ll i = 1; i <= N; i++) {
    s[i] = 2 * s[i - 1] + 3;
    p[i] = 2 * p[i - 1] + 1;
  }

  cout << f(N, X) << endl;
  return 0;
}