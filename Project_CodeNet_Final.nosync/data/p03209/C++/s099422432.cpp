#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll rec(ll N, ll X)
{
  if (N == 0) {
    return 1;
  }
  if (X == 1) {
    return 0;
  }
  ll H = pow(2, N + 1) - 3;
  if (H + 2 == X) {
    return pow(2, N);
  }
  if (H + 1 >= X) {
    return rec(N - 1, X - 1);
  }
  else {
    return pow(2, N) + rec(N - 1, X - H - 2);
  }
}

int main()
{
  ll N, X;
  cin >> N >> X;
  cout << rec(N, X) << endl;
}
