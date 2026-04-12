// https://atcoder.jp/contests/

#include <bits/stdc++.h>
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPR(i, n) for (int(i) = (n); (i) >= 0; (i)--)
#define FOR(i, m, n) for (int(i) = (m); (i) < (n); i++)
#define INF 1e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, a, b, cnt;
vector<set<int>> g;

void search(int s, set<int> v)
{
  if (v.find(s) != v.end())
    return;

  v.insert(s);
  if (v.size() == N)
  {
    cnt++;
    return;
  }

  for (auto &p : g[s])
    search(p, v);
}

int main()
{
  set<int> s;
  cnt = 0;

  cin >> N >> M;
  REP(i, N)
  {
    g.push_back(s);
  }
  REP(i, M)
  {
    cin >> a >> b;
    g[a - 1].insert(b - 1);
    g[b - 1].insert(a - 1);
  }

  search(0, s);

  cout << cnt << '\n';

  return 0;
}
