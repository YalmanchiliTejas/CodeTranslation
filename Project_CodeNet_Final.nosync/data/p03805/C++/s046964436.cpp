#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> vec(n + 1, vector<int>(n + 1));
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    vec[a][b] = 1;
    vec[b][a] = 1;
  }
  vector<int> v(n);
  rep(i, n) v[i] = i + 1;
  int ans = 0;
  sort(v.begin(), v.end());
  do
  {
    if (v[0] != 1)
      break;
    bool ok = true;
    rep(i, n - 1)
    {
      if (vec[v[i]][v[i + 1]] == 0)
        ok = false;
    }
    if (ok)
      ans++;
  } while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
  return 0;
}