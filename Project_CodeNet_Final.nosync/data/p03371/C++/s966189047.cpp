#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int cost = 0;
  if (a+b >= 2*c) {
    cost = 2*c*min(x,y);
    if (x >= y) cost += (x-y) * min(2*c, a);
    else cost += (y-x) * min(2*c, b);
  }
  else {
    cost = x * min(a, 2*c) + y * min(b,2*c);
  }
  cout << cost << endl;
}
