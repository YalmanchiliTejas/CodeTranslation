#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;

  int ans_ab = a * x + b * y;
  int ans_abc = (x > y)?( 2 * c * y + a * (x-y)):(2 * c * x + b * (y-x));
  int ans_c = (x>y)?2*c * x:2*c*y;

  cout<<min(min(ans_ab,ans_abc),ans_c)<<endl;

  return 0;
}
