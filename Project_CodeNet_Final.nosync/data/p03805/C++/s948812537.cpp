#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, n) for (int i = s; i < n; i++)

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<bool>> g(N, vector<bool>(N, false));
  rep(i, 0, M)
  {
    int a, b;
    cin >> a >> b;
    g.at(--a).at(--b) = true;
    g.at(b).at(a) = true;
  }
  vector<int> A(N - 1);
  rep(i, 1, N)
  {
    A.at(i - 1) = i;
  }
  int ans = 0;
  do
  {
    bool flag = true;
    if (!g.at(0).at(A.at(0)))
    {
      continue;
    }
    rep(i, 0, N - 2)
    {
      if (!g.at(A.at(i)).at(A.at(i + 1)))
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      ans++;
    }
  } while (next_permutation(A.begin(), A.end()));
  cout << ans << endl;
}