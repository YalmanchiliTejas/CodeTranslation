#include <iostream>
using namespace std;
int main(){
  int a,b,c,x,y;cin>>a>>b>>c>>x>>y;
  if(a+b < c*2){
    cout << a*x+b*y << endl;
    return 0;
  }
  int ans = 0;
  ans += min(x,y)*2*c;
  if(x > y){
    ans+= min(a,c*2)*(x-y);
  }else if (x < y){
    ans+= min(b,c*2)*(y-x);
  }
  cout << ans << endl;
}