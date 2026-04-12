#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[100000];
  REP(i, n)
  {
    cin >> a[i];
  }

  multiset<int> ms;
  REP(i, n)
  {
    if (ms.empty())
    {
      ms.insert(-a[i]);
      continue;
    }

    auto itr = ms.upper_bound(-a[i]);
    if (itr == ms.end())
    {
      ms.insert(-a[i]);
    }
    else
    {
      ms.erase(itr);
      ms.insert(-a[i]);
    }
  }

  cout << ms.size() << endl;
}
