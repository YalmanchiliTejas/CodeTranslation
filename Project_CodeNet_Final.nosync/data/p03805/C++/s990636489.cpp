#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  // 隣接グラフ表現
  vector<vector<bool>> G(N, vector<bool>(N, false));
  for (int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G.at(a).at(b) = true;
    G.at(b).at(a) = true;
  }

  int ans = 0;
  vector<int> order(N - 1);
  for (int i = 0; i < N - 1; i++)
  {
    order.at(i) = i + 1;
  }
  // O(N(N!))のアルゴリズム
  do
  {
    int exist = true;
    if (G.at(0).at(order.at(0)))
    {
      for (int i = 0; i < N - 2; i++)
      {
        if (!G.at(order.at(i)).at(order.at(i + 1)))
        {
          exist = false;
          break;
        }
      }
    }
    else
    {
      exist = false;
    }
    if (exist)
    {
      ans++;
    }
  } while (next_permutation(order.begin(), order.end()));
  cout << ans << endl;
}