#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
  int a, b, c, x, y;
  int ans = 0;

  cin >> a >> b >> c >> x >> y;

  int maxn = max(x, y);

  int ansmin = a*x+b*y+c*x+c*y;
  int tmp = 0;

  for(int ic = 0; ic<= maxn; ic++){
    int xx = (x - ic)>0 ? (x - ic) : 0;
    int yy = (y - ic)>0 ? (y - ic) : 0;
    tmp += ic*2*c;
    tmp += xx*a;
    tmp += yy*b;
    ansmin = min(ansmin, tmp);
    tmp = 0;
  }
  ans = ansmin;

  cout << ans << endl;

}
