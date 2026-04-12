#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
  int a, b, c; //ピザの値段
  int x, y;    //必要な枚数
  cin >> a >> b >> c >> x >> y;

  if (x <= y)
  {
    int tmp = std::min(2 * c * x + b * (y - x), 2 * c * y);
    cout << std::min(tmp, a * x + b * y) << endl;
  }
  else
  {
    int tmp = std::min(2 * c * y + a * (x - y), 2 * c * x);
    cout << std::min(tmp, a * x + b * y) << endl;
  }
}