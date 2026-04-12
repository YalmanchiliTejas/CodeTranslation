#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main()
{
  int r, g, b;
  cin >> r >> g >> b;

  int tmp = 100 * r + 10 * g + b;

  if(tmp %4 == 0)
    cout << "YES";
  else
  {
    cout << "NO";
  }


}
