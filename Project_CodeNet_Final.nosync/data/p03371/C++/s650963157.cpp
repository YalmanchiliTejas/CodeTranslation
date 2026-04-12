#include <bits/stdc++.h>
using namespace std;

int main() {
 int a,b,c,x,y;
  cin >>a>>b>>c >>x>>y;
int d = a*x + b *y;
  int e = c*2 * max(x,y);
  int f;
  if(x>y) f =  c *2* y + a * (x-y);
  else f = c*2*x+b*(y-x);
  int ans =min(min(d,e),f);
  printf("%ld\n",ans);
}