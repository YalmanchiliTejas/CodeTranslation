#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> p;


int main()
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll tmp1 = a * x + b * y;
  ll tmp2 = max(x, y) * 2 * c;
  ll tmp3 = min(x, y) * 2 * c;
  if (x > y) {
    tmp3 += ((max(x, y)-min(x, y)) * a);
  }else{
    tmp3 += ((max(x, y)-min(x, y)) * b);
  }
  tmp1 = min(tmp1, tmp2);
  cout << min(tmp1, tmp3) << endl;
  return 0;
}
