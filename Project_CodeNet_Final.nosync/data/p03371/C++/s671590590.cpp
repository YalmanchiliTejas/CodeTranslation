#include <bits/stdc++.h>
using namespace std;


int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int sum = 0;
  if(x>=y){
    if(a+b <= c*2){
      sum = a*x + b*y;
    }
    else if(a <= c*2){
      sum = c*2*y + a*(x-y); 
    }
    else{
      sum = c*2*x;
    }
  }
  else{
    if(a+b <= c*2){
      sum = a*x + b*y;
    }
    else if(b <= c*2){
      sum = c*2*x + b*(y-x); 
    }
    else{
      sum = c*2*y;
    }
  }
  cout << sum << endl;
}