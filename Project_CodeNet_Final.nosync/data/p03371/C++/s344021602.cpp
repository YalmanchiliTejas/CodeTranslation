#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  ll ans = a*x+b*y;
  ans = min(ans,min(x,y)*2*c+(x-min(x,y))*a+(y-min(x,y))*b);
  ans = min(ans,max(x,y)*2*c);
  cout << ans << endl;
}
