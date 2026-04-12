#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if(a + b > c * 2){
   	int w = min(x,y);
    x -= w;
    y -= w;
    ans += w * c * 2;
    if(x == 0 && y == 0){
      cout << ans << endl;
      return 0;
    }
  }
  if(a > c * 2){
    ans += x * c * 2;
    x = 0;
    if(x == 0 && y == 0){
      cout << ans << endl;
      return 0;
    }
  }
  if(b > c * 2){
    ans += y * c * 2;
    y = 0;
    if(x == 0 && y == 0){
      cout << ans << endl;
      return 0;
    }
  }
  ans += x * a + y * b;
  cout << ans << endl;
}