// https://atcoder.jp/contests/abc124/tasks/abc124_b

#include <bits/stdc++.h>
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, n) for (int(i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for (int(i) = (m); (i) < (n); i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main()
{
  int N, h, maxH, r = 1;
  cin >> N;

  cin >> maxH;
  REP(i, N - 1)
  {
    cin >> h;
    if (maxH <= h)
      r++;
    maxH = max(maxH, h);
  }

  cout << r << '\n';

  return 0;
}
