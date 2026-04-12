#include <iostream>
#include <utility>
#include <stack>
using namespace std;

int main()
{
  int n, m;
  int mat[10][10] = {0};
  cin >> n >> m;
  for (int i = 0; i < m; ++i)
  {
    int a, b;
    cin >> a >> b;
    mat[a][b] = mat[b][a] = 1;
  }

  int end = 0;
  for (int i = 1; i <= n; ++i)
  {
    end = end | (1 << i);
  }

  stack<pair<int, int>> stack; // (今いる場所, 到達した場所)
  stack.push(make_pair(1, 1 << 1));
  int count = 0;
  while (!stack.empty())
  {
    auto p = stack.top();
    stack.pop();

    if ((p.second & end) == end)
    {
      // 全部通った
      count++;
      continue;
    }

    for (int i = 1; i <= n; ++i)
    {
      // 今いるところに連結していて、まだ移動していない場所なら移動する
      if (mat[p.first][i] > 0 && (p.second & (1 << i)) == 0)
      {
        stack.push(make_pair(i, p.second | (1 << i)));
      }
    }
  }
  cout << count << endl;
  return 0;
}
