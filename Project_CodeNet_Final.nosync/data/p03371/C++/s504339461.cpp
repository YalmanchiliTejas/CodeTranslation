#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  if(x<y) cout<<min({a*x+b*y,y*c*2,c*x*2+b*(y-x)})<<endl;
  else cout<<min({a*x+b*y,x*c*2,c*y*2+a*(x-y)})<<endl;
 
}