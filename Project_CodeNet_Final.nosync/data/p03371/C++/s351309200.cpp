#include<bits/stdc++.h>
using namespace std;
#define com(x,y,c,s) s+=c*x;y-=x;x=0;
#define abc(a,c,x) (a>c?c:a)*x
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main() {
  int a, b, c, x, y, sum = 0;
  cin >> a >> b >> c >> x >> y;
  c *= 2;
  if (a + b >= c) {
    if (x < y) {
      com(x, y, c, sum)
    } else {
      com(y, x, c, sum)
    }
  }
  sum += abc(a, c, x);
  sum += abc(b, c, y);
  cout << sum;
}
