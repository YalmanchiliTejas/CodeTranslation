#include <bits/stdc++.h>
using  namespace std;

int main(){
  int a, b, c, x, y, ans;
  cin >> a >> b >> c >> x >> y;
  
  if(a+b>2*c){
    if(max(x,y)*2*c<(min(x,y)*2*c+abs(x-y)* ((x>y)?a:b))){
      ans = max(x,y)*2*c;
    }else{
      ans = min(x,y)*2*c+abs(x-y)* (x>y?a:b);
    }
  }else{
    ans = x*a + y*b;
  }
  cout << ans << endl;
  return 0;

}
