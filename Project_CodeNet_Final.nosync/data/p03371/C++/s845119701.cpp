#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y,ans=0;
  cin >> a >> b >> c >> x >> y;
  
  a=min(a,2*c);
  b=min(b,2*c);
  
  int k=min(x,y);
  ans+=k*min(a+b,2*c);
  x-=k;
  y-=k;
  ans+=x*a+y*b;
  
  cout << ans;
  
  
}