#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <functional>
#include <cstdint>
#define REP(i, n) for(ll i = 0; i < n; i++)
using namespace std;


int main() {

  cin.tie(0);
  ios::sync_with_stdio(false);

  int a,b,c,x,y,ans;
  cin >> a >> b >> c >> x >> y;
  
  if(a+b > c*2){
    int ans1;
    if(x<y){
      ans1 = c*2*x + (y-x)*b;
    } else {
      ans1 = c*2*y + (x-y)*a;
    }
    int ans2 = c*2*max(x,y);
    ans = min(ans1, ans2);

  } else {
    ans = a*x + b*y;
  }
  cout << ans << endl;

}
  
