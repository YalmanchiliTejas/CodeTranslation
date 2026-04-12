#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c,x,y;
  int ans = 0;
  cin >> a >> b >> c >> x >> y;
  if(a+b<= 2*c){
    ans += a*x+b*y ;
  }
  else{
    if(x<=y && 2*c<=b){
      ans += 2*c*y;
    }else if(y<=x && 2*c<=a){
      ans += 2*c*x;
    }else if(x<=y && b <= 2*c){
      ans += 2*c*x+(y-x)*b;
    }else if(y<=x && a <= 2*c){
      ans += 2*c*y +(x-y)*a;
    }
  }
  cout << ans <<endl;
}
    
  