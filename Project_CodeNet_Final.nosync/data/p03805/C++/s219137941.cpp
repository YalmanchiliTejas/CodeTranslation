#include <iostream>
#include <typeinfo>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int N, M;
vector<int> a, b;

int main()
{
  cin >> N >> M;
  a.resize(M);
  b.resize(M);
  for (int i = 0; i < M; i++)
  {
    cin >> a[i];
    a[i]--;
    cin >> b[i];
    b[i]--;
  }

  vector<int> order(N);
  for (int i = 0; i < N; i++)
  {
    order[i] = i;
  }

  int ans = 0;
  do
  {
    // 始点が0でなくなれば終了
    if (order[0] != 0)
    {
      break;
    }
    // order[i]からorder[i+1]への道があるかどうか、i=0, ... ,N-1について確かめる
    bool ok = true;
    for (int i = 0; i < N - 1; i++)
    {
      // (a[j],b[j])の組が(order[i],order[i+1])の組と一致するかどうか
      bool flag = false;
      for (int j = 0; j < M; j++)
      {
        if (a[j] == order[i] && b[j] == order[i + 1])
        {
          flag = true;
        }
        else if (b[j] == order[i] && a[j] == order[i + 1])
        {
          flag = true;
        }
      }
      if (!flag)
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      ans++;
    }
  } while (next_permutation(order.begin(), order.end()));

  cout << ans << endl;
}