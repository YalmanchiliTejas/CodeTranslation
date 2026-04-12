#include <iostream>
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  if(a >= c * 2 && b >= c * 2){
    cout << max(x,y) * c * 2 << endl;
    return 0;
  }

  if(a + b < c * 2){
    cout << a * x + b * y << endl;
    return 0;
  }
  
  int ans;
  ans = c * min(x,y) * 2;

  if(min(x,y) == x){
    if(b >= c * 2)
      ans+=c*2*(y-x);
    else
      ans+=b*(y-x);
  } else {
    if(a >= c * 2)
      ans+=c*2*(x-y);
    else
      ans+=a*(x-y);
  }
  cout << ans << endl;
  
  return 0;
}
