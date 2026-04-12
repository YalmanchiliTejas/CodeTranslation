#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int kotae=a*x+b*y;
  for( int i=0;i<=max(x,y);i++){
    if(x-i<=0)a=0;
    if(y-i<=0)b=0;
    kotae=min(kotae,a*(x-i)+b*(y-i)+c*2*i);
  }
  cout <<kotae<<endl;
}