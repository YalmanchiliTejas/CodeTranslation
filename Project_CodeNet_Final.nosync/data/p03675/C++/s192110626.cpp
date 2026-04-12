#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;

ll dp[300010];

int main()
{
  int n;
  cin >> n;
  list<int> a;
  if (n % 2 == 0)
  {
    for (int i = 0; i < n; ++i)
    {
      int t;
      cin >> t;
      if (i % 2 == 0)
      {
        a.push_back(t);
      }
      else
      {
        a.push_front(t);
      }
    }
  }
  else
  {
    for (int i = 0; i < n; ++i)
    {
      int t;
      cin >> t;
      if (i % 2 == 0)
      {
        a.push_front(t);
      }
      else
      {
        a.push_back(t);
      }
    }
  }
  cout << a.front();
  for (auto itr = a.begin(); itr != a.end(); ++itr)
  {
    if (itr == a.begin())
      continue;
    cout << ' ' << *itr;
  }
  cout << endl;

  return 0;
}
