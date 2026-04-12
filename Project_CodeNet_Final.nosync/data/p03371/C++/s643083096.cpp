#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y;
  cin >> a >> b >>c >> x >> y;
  if(a+b >= 2*c){
    int ans;
    if(x>y){
      ans = y * 2 * c + (x-y) * a;
      ans = min(ans, 2*x*c);   
    }else{
      ans = x * 2 * c + (y-x) * b;
      ans = min(ans, 2*y*c);   
    }
    cout << ans << endl;
  }else{
    cout << a*x + b*y << endl;
  }
}