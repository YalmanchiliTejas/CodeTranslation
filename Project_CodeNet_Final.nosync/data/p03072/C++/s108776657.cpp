#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int h;
  vector<int> hs;

  for (int i = 0; i < n; i++)
  {
    cin >> h;
    hs.push_back(h);
  }

  int res = 0;
  for (int i = 0; i < n; i++)
  {
    bool suc = true;
    for (int j = 0; j < i; j++)
    {
      if (hs[i] < hs[j])
      {
        suc = false;
        break;
      }
    }
    if (suc)
    {
      res++;
    }
  }

  cout << res << endl;
}