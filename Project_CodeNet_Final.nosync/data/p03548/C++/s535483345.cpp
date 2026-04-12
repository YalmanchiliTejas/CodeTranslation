#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int x, y, z, cnt = 0;
  cin >> x >> y >> z;

  x -= z;

  while (1)
  {
    if (x < y + z)
    {
      break;
    }

    x -= y + z;
    cnt++;
  }
  cout << cnt << endl;
}
