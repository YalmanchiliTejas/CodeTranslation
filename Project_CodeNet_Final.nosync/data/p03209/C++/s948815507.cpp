#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll rec(ll N, ll X)
{
  if (X == 0) {
    return 0;
  }
  if (N == 0) {
    return 1;
  }
  ll H = pow(2, N + 2) - 3;
  ll P = pow(2, N + 1) - 1;
  if (X <= H / 2) {
    return rec(N - 1, X - 1);
  }
  else if (X == H / 2 + 1) {
    return P / 2 + 1;
  }
  else {
    return P / 2 + 1 + rec(N - 1, X - H / 2 - 1);
  }
}

int main()
{
  ll N, X;
  cin >> N >> X;
  cout << rec(N, X) << endl;
}
