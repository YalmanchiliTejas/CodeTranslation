#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int N, M;
bool path[8][8];
bool visit[8];

int dfs(int point)
{
  visit[point] = true;
  bool all_visit = true;
  REP(i, N)
  {
    if (!visit[i])
      all_visit = false;
  }
  if (all_visit)
    return 1;
  int res = 0;
  REP(i, N)
  {
    if (path[point][i] && !visit[i])
    {
      res += dfs(i);
      visit[i] = false;
    }
  }
  return res;
}

int main()
{
  cin >> N >> M;
  vector<int> a(M), b(M);
  REP(i, M)
  {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  REP(i, 8)
  REP(j, 8)
  path[i][j] = false;
  REP(i, 8)
  visit[i] = false;
  REP(i, M)
  {
    path[a[i]][b[i]] = true;
    path[b[i]][a[i]] = true;
  }
  cout << dfs(0) << endl;
  return 0;
}