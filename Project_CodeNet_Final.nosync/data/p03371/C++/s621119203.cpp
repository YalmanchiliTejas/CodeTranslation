#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans=0;
  if(x==y)
    ans = min({ a*x+b*y, c*x*2});
  else if(x>y)
    ans = min({ a*x+b*y, c*x*2, c*y*2+a*(x-y)});
  else
    ans = min({ a*x+b*y, c*y*2, c*x*2+b*(y-x)});
  cout << ans << endl;
  return 0;
}