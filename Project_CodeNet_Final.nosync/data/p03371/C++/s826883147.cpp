#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  c*=2;
  set<int>s;
  s.insert(max(x,y)*c);
  s.insert(a*x+b*y);
  s.insert(min(x,y)*c+abs(x-y)*(x>y?a:b));

  cout<<*begin(s)<<endl;
}