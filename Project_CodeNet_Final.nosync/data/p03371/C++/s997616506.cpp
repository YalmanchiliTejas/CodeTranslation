#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  int a,b,ab,x,y;
  cin >> a >> b >> ab >> x >> y;
  int amin = 0;
  int bmin = 0;
  int abmin = 0;
  amin = min(a,ab * 2);
  bmin = min(b,ab * 2);
  abmin = min(a + b,ab * 2);
  int both = 0;
  both = min(x,y);
  cout << both * abmin + (x - both) * amin + (y - both) * bmin << endl;
  return 0;
}