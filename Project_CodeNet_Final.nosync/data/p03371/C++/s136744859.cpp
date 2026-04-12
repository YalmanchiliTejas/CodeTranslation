#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  cout<<min({a*x+b*y,c*max(x,y)*2,c*x*2+max(0,(y-x)*b),c*y*2+max(0,(x-y)*a)})<<endl;
}