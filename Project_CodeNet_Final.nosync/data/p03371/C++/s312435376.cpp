#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  long ans = 0;
  int tmp;
  if(a+b>2*c){
    tmp = min(x,y);
    ans += tmp*2*c;
    x-=tmp;
    y-=tmp;
  }
  if(x>0){
    if(a>2*c) ans += 2*c*x;
    else ans += a*x;
  }
  if(y>0){
    if(b>2*c) ans += 2*c*y;
    else ans += b*y;
  }
  cout <<ans;


  
  
}