#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
constexpr auto INF = 2147483647;
typedef long long ll;

int main(){
  int a, b, c, x, y, ans;
  int a_n, b_n, c_n;
  a_n = b_n = c_n = 0;
  cin >> a >> b >> c >> x >> y;
  if(a+b > c*2){
    c_n = min(x,y);
    x -= c_n;
    y -= c_n;
    c_n *= 2;
    if(a > 2*c && x>0){
      c_n += x*2;
      x = 0;
    }else if(b > c*2 && y>0){
      c_n += y*2;
      y = 0;
    }
  }
  a_n = x;
  b_n = y;
  
  ans = a_n*a + b_n*b + c_n*c;
  cout << ans << endl;

  return 0;
}