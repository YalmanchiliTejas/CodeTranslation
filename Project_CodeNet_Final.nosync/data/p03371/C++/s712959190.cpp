#include <iostream>

using namespace std;

int main() {

  int a, b, c, x, y, ans = 0;
  cin >> a >> b >> c >> x >> y;
  if(2 * c < a + b){
    ans += (2 * c) * min(x, y);
    if(x > y){
      if(2 * c < a){
        ans += (2 * c) * (x - y);
      }else{
        //cerr << ans << '\n';
        ans += a * (x - y);
      }
      //cerr << "NO";
      cout << ans;
    }else if(y > x){
      if(2 * c < b){
        ans += (2 * c) * (y - x);
      }else{
        ans += b * (y - x);
      }
      //cerr << "No";
      cout << ans;
    }else{
      cout << ans;
    }

  }else{
    cout << x * a + y * b;
  }
  return 0;
}
