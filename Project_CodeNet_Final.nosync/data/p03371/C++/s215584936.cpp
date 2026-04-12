#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
using namespace std;


int main(void) {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int dbl = min(x,y);
  int cost1 = a*dbl + b*dbl;
  int cost2 = c*2*dbl;
  int cost = min(cost1,cost2);
  x-=dbl;
  y-=dbl;
  cost += (a*x + b*y < c*2*max(x,y))?(a*x + b*y):c*2*max(x,y);
  cout << cost << endl;
}
