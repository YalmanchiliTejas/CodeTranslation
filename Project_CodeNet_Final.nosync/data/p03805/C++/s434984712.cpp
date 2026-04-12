#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define printYes() cout << "Yes" << endl;
#define printNo() cout << "No" << endl;
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> graph(N, vector<bool>(N, false));
  rep(i, M)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a][b] = true;
    graph[b][a] = true;
  }

  vector<int> root(N - 1);
  rep(i, N - 1)
  {
    root[i] = i + 1;
  }

  int ans = 0;
  do
  {
    if (!graph[0][root[0]])
      continue;

    bool is_ok = true;
    rep(i, root.size() - 1)
    {
      if (!graph[root[i]][root[i + 1]])
        is_ok = false;
    }
    if (is_ok)
      ans++;
  } while (next_permutation(root.begin(), root.end()));

  cout << ans << endl;
  return 0;
}