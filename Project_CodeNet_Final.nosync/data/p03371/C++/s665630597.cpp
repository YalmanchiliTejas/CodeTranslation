#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;
  
  if(a+b<=c*2){
    cout<<a*x+b*y<<endl;
  return 0;}
  
  if(x>=y){
    if(a<=2*c){
      cout<<2*c*y+a*(x-y)<<endl;}
    else cout<<2*c*x<<endl;
  }
  
  else{
    if(b<=2*c){
      cout<<2*c*x+b*(y-x)<<endl;}
    else cout<<2*c*y<<endl;
  }

  
}
