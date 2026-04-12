#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;

  int tmp;
  int tmpy;
  if(a+b >= c*2){
    ans = min(x,y) * c*2;
    tmp = min(x,y);
    x -= tmp;
    y -= tmp;
    if(x > y){
      tmp = x;
      tmpy = a;
    }else{
      tmp = y;
      tmpy = b;
    }


    if(tmpy <= c*2){
      ans += tmp * tmpy;
    }else{
      ans += tmp * c*2;
    }
  }else{
    if(a > c*2){
      ans = x * c*2;
      y -= x;
      if(y > 0){
        if(b > c*2){
          ans += y*c*2;
        }else{
          ans += y*b;
        }
      }
    }else if(b > c*2){
      ans = y * c*2;
      x -= y;
      if(x > 0){
        if(a > c*2){
          ans += x*c*2;
        }else{
          ans += x*a;
        }
      }
    }else{
      ans = x*a+y*b;
    }
  }

  cout << ans << endl;
  return 0;
}
