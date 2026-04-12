#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int tmp,tmp1,tmp2;
  tmp = a*x+b*y;
  tmp1 = 2*c*max(x,y);
  tmp2 = 2*c*min(x,y);
  if(x<y) tmp2 += b*(y-x);
  else if(y<x) tmp2 += a*(x-y);
  
  cout << min(tmp,min(tmp1,tmp2)) << endl;
}