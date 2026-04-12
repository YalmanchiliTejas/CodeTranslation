#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  cout<<min({max(x,y)*2*c,min(x,y)*2*c+(x-min(x,y))*a+(y-min(x,y))*b,x*a+y*b})<<endl;
}