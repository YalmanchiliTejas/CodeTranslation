#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn long long

typedef long long ll;
typedef pair<ll,ll> p;


int main()
{
  int x, y, z;
  cin >> x >> y >> z;
  int res = 0;
  int tmp = x;
  x -= z;
  for (int i = 0; i <= tmp + z; i++)
  {
    x -= (y + z);
    res++;
    if(x < y + z)
    {
      cout << res << endl;
      return 0;
    }
    // cout << i << endl;
  }
  cout << x << endl;
}