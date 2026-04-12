#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn int

typedef long long ll;
typedef pair<ll,ll> p;


int main()
{
  int h, w;
  cin >> h >> w;
  vector<string> v(h, "@");
  for (int i = 0; i < h; i++)
  {
    cin >> v[i];
  }

  for (int i = 0; i < h; i++)
  {
    bool flag = true;
    for (int j = 0; j < w; j++)
    {
      if(v[i][j] == '#') flag = false;
    }
    if(flag)
    {
      v.erase(v.begin() + i);
      i--;
      h--;
    }
  }

  for (int i = 0; i < w; i++)
  {
    bool flag = true;
    for (int j = 0; j < h; j++)
    {
      if(v[j][i] == '#') flag = false;
    }
    if(flag)
    {
      for (int j = 0; j < h; j++)
      {
        v[j].erase(v[j].begin() + i);
      }
      i--;
      w--;
    }
  }

  for (int i = 0; i < h; i++)
  {
    cout << v[i] << endl;
  }
}