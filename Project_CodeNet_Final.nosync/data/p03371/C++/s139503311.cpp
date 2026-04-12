#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int ans;
  if(2*c <= a && 2*c <= b){
    ans = max(x, y)*2*c;
  }else if(2*c <= a){
    ans = 2*c*x + b*max(0, y-x);
  }else if(2*c <= b){
    ans = a*max(0, x-y) + 2*c*y;
  }else if(a+b >= 2*c){
    ans = 2*c*min(x, y) + a*max(x-y, 0) + b*max(y-x, 0);
  }else{
    ans = a*x + b*y;
  }
  
  cout << ans << endl;
  
  return 0;
}