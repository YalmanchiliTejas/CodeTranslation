#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  cout<<min({a*x+b*y,max(x,y)*2*c,(x<y?x*2*c+(y-x)*b:y*2*c+(x-y)*a)});
}