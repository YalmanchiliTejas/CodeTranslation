#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int a, b, c, x, y;

  cin >> a >> b >> c >> x >> y;

  int cyen = c * 2;
  int minxy = min(x, y);
  int ans = 0;

  if(cyen < a+b){
    ans = cyen * minxy;
    x -= minxy;
    y -= minxy;

    ans += x * min(a, cyen);
    ans += y * min(b, cyen);
  }

  else ans = a*x + b*y;

  cout << ans << endl;

  return 0;

}
