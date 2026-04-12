#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int h;
  cin >> h;
  int ans = 1;
  for (int i = 0; i < n - 1; i++)
  {
    int m;
    cin >> m;
    if (m >= h)
    {
      ans++;
      h = m;
    }
  }
  cout << ans << endl;
}
