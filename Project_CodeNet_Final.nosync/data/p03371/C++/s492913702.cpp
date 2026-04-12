#include <bits/stdc++.h>
using namespace std;
  
int main() {
  long long a , b , c , x , y ;
  cin >> a >> b >> c >> x >> y ;
  
  if(a+b<=c*2){
    cout << a*x+b*y << endl;
  }
  else{
    if(c*2<=a&&c*2<=b){
      if(x<=y){
        cout << c*y*2 << endl;
      }
      else{
        cout << c*x*2 << endl;
      }
    }
    else{
      if(x<=y){
        if(b<=c*2){
          cout << c*x*2+b*(y-x) << endl;
        }
        else{
          cout << c*x*2+c*2*(y-x) << endl;
        }
      }
      else{
        if(a<=c*2){
          cout << c*y*2+a*(x-y) << endl;
        }
        else{
          cout << c*y*2+c*2*(x-y) << endl;
        }
      }
    }
  }
}