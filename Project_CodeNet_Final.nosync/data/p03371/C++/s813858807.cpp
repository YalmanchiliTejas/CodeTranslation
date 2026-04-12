#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int i,j,k,n,m;
string s;

int main() {
  int a,b,c,x,y;cin >> a >> b>> c>> x>> y;
  int out;
  if (a+b <= 2*c) {
    out = a*x + b*y;
  } else {
    int p2 = 2 * c * max(x,y);
    int p3 = 2 * c * min(x,y);
    if (x>y) {
      p3 += a * (x-y);
    } else {
      p3 += b * (y-x);
    }
    out = min(p2, p3);
  }
  cout << out << endl;
  return 0;
}
