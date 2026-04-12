
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int set;
  cin >> set;
  for(int cnt = 0; cnt < set; cnt++)
  {
    int a, c, n, m, v, tmp, ans = 0;
    double b;
    cin >> v >> n >> m;
    for(int i = 0; i < m; i++)
    {
      tmp = 0;
      cin >> a >> b >> c;
      int vv = v;
      for(int j = 0; j < n; j++)
      {
        if(a == 0)
        {
          tmp += (int)(vv * b);
          vv -= c;
        }
        else
        {
          vv += (int)(vv * b);
          vv -= c;
        }
      }
      ans = max(ans, vv + tmp);
    }
    cout << ans << endl;
  }
}