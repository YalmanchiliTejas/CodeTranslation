// https://atcoder.jp/contests/abc058/tasks/arc071_a

#include <bits/stdc++.h>
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, n) for (int(i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for (int(i) = (m); (i) < (n); i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll n, p;
string S, m, t;

int main()
{
  cin >> n;
  cin >> m;
  sort(ALL(m));
  REP(i, n - 1)
  {
    cin >> S;
    sort(ALL(S));
    t = "";
    p = 0;
    for (char &c : m)
    {
      if (S.length() <= p)
        break;

      if (c == S[p])
      {
        p++;
        t += c;
      }
      else if (S.find(c) != string::npos && p < S.find(c))
      {
        p = S.find(c) + 1;
        t += c;
      }
    }
    m = t;
  }

  cout << m << '\n';

  return 0;
}
