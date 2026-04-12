#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int d,e,f;
  d=a*x+b*y;
  e=c*2*max(x,y);
  if(x>y){
    f=2*c*y+a*(x-y);
  }
  else{
    f=2*c*x+b*(y-x);
  }
  cout<<min(d,min(e,f))<<endl;
  
}