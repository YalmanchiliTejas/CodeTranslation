#include<bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if(a + b < c * 2){
    ans = x * a + b * y;
  }else{
    if(x < y){
      ans = min(x * 2 * c + (y - x) * b, y * 2 * c);
    }else{
      ans = min(y * 2 * c + (x - y) * a, x * 2 * c);
    }
  }
  cout << ans << endl;

  return 0;
}


