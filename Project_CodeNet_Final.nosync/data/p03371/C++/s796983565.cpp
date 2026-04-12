#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
  int a,b,c,x,y,ans;
  cin >> a >> b >> c >> x >> y;
  if (a+b > c*2){
    if (x<y){
      if (b<c*2) ans=c*2*x+b*(y-x);
      else ans=c*2*y;
    }else{
      if (a<c*2) ans=c*2*y+a*(x-y);
      else ans=c*2*x;
    }
  }else{
    ans=a*x+b*y;
  }
  cout << ans << endl;
  return 0;
}