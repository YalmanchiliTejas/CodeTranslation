#include <iostream>
#include <vector>
#define ll long long
using namespace std;
ll N, X, a[55], p[55];

ll f(ll N, ll X) {
  if (N == 0)
    return X <= 0 ? 0 : 1;
  else if (X <= a[N - 1] + 1)
    return f(N - 1, X - 1);
  else
    return p[N - 1] + 1 + f(N - 1, X - a[N - 1] - 2);
}

int main() {
  cin >> N >> X;

  a[0] = 1;
  p[0] = 1;
  for (int i = 1; i < N + 1; i++) {
    a[i] = 2 * a[i - 1] + 3;
    p[i] = 2 * p[i - 1] + 1;
  }

  cout << f(N, X) << endl;
  return 0;
}