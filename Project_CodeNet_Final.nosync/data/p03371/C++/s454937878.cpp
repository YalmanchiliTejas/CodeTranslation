#include <bits/stdc++.h>

using namespace std;
int a,b,c,x,y,res;
int main(){
  cin>>a>>b>>c>>x>>y;
  res = min(a*x+b*y,min(c*2*(max(x,y)),c*2*min(x,y)+max(x-min(x,y),0)*a+max(y-min(x,y),0)*b));
  cout<<res;
  return 0;
}
