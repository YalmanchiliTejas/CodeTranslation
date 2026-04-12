#include<bits/stdc++.h>
using namespace std;
signed main(){
  int a,b,c,d,e,f,g;
  cin>>a>>b>>c>>d>>e;
  if((a+b)<c*2) cout<<d*a+b*e;
  else{
    f=c*(max(e,d)*2);
    g=c*(min(e,d)*2);
    if(e<d) g+=(a*(d-e));
    else g+=(b*(e-d));
    if(f<g) cout<<f;
    else cout<<g;
  }
  cout<<"\n";
}