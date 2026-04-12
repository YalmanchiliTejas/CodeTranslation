#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if(a+b > c*2){
    int z = min(x,y);
    ans += z * c * 2;
    x -= z;
    y -= z;
  }
  //cout << ans << endl;
  if(a > c*2){
    ans += x * c * 2;
  }else{
    ans += x * a;
  }
  //cout << ans << endl;
  if(b > c*2){
    ans += y * c * 2;
  }else{
    ans += y * b;
  }
  cout << ans << endl;
}