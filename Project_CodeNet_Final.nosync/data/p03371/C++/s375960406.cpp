#include <iostream>

using namespace std;

int main(){
  int a, b, c, x, y, lp, tmp, ans=1000000007;
  cin>> a >> b >> c >> x >> y;
  lp=max(x, y);
  c*=2;
  
  for(int i=0;i<=lp;i++){
  	tmp=max(0, a*(x-i))+max(0, b*(y-i))+i*c;
  	ans=min(ans, tmp);
  //cout<< i << " " << ans <<endl;
  }

  cout<< ans <<endl;

  return 0;
}
