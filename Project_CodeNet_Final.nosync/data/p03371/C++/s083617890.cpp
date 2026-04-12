#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if(a + b <= 2 * c) cout << a * x + b * y << endl;
  else if(x > y){
    int ans1 = a * (x - y) + 2 * c * y;
    int ans2 = 2 * c * x;
    int ans = ans1 > ans2 ? ans2 : ans1;
    cout << ans << endl;
  }
  else{
    int ans1 = 2 * c * x + b * (y - x);
    int ans2 = 2 * c * y;
    int ans = ans1 > ans2 ? ans2 : ans1;
    cout << ans << endl;
  }
  return 0;
}