#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;c*=2;
  cout<<min(a*x+b*y,c*min(x,y)+abs(x-y)*min((x>y?a:b),c));
}