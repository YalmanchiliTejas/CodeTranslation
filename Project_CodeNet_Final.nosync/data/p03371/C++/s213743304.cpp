#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a,b,c,x,y,sum;
  sum = 0;

  cin >> a >> b >> c >> x >> y;

  if(c*2 <= a + b){
    if(x <= y){
      if(2*c <= b){
        sum += c * 2*y;
        x -= x;
        y -= y;
      }
      else{
        sum += c * 2*x;
        y -= x;
        x -= x;
      }
    }
    else{
      if(2*c <= a){
        sum += c * 2*x;
        x -= x;
        y -= y;
      }
      else{
        sum += c * 2*y;
        x -= y;
        y -= y;
      }
    }
  }
  if(c*2 <= a){
    sum += c*2 * x;
    x -= x;
  }
  if(c*2 <= b){
    sum += c*2 * y;
    y -=y;
  }
  sum += x * a + y * b;
  cout << sum << endl;
  return 0;
}
