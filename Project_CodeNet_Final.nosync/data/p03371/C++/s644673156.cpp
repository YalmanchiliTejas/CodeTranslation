#include<iostream>
using namespace std;
int main(){
   int ans = 0;
   int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
   if(a + b > 2 * c){
    ans = min(x,y) * 2 * c;
    if(x > y){
      if(a * (x-y) > 2 * c*(x-y))
        ans += 2*c*(x - y);
      else
        ans += a*(x-y);
    }
    else{
      if(b * (y-x) > 2 * c*(y-x))
        ans += 2 * c*(y - x);
      else
        ans += b * (y - x);
    }
   }
   else
     ans = x * a + y * b;
  
  cout << ans;
      
}