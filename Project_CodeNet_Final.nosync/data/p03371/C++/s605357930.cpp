// https://atcoder.jp/contests/

#include <bits/stdc++.h>
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, n) for (int(i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for (int(i) = (m); (i) < (n); i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int A, B, C, X, Y;
ll c = 0;

int main()
{
  cin >> A >> B >> C >> X >> Y;

  if (A + B < 2 * C)
    c = A * X + B * Y;
  else if (X == Y)
    c = X * 2 * C;
  else if (X < Y)
    c = X * 2 * C + (Y - X) * min(B, 2 * C);
  else
    c = Y * 2 * C + (X - Y) * min(A, 2 * C);

  cout << c << '\n';

  return 0;
}
