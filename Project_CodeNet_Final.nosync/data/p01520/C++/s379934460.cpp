#include <iostream>
using namespace std;

int main(void)
{
  int n, t, e;
  cin >> n >> t >> e;

  int x;
  int buf;
  bool flag = false;
  for (int i = 0; i < n; ++i)
  {
    cin >> x;
    buf = x;
    while (buf <= t+e)
    {
      if (t-e <= buf and buf <= t+e)
      {
        cout << i + 1 << endl;
        flag = true;
        break;
      }
      buf += x;
    }
    if (flag) break;
  }
  if (! flag) cout << -1 << endl;
  return 0;
}