#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  ll ans=0;
  if(A+B<2*C){
    ans=X*A+Y*B;
  }
  else{
    if(X<Y){
      if(B<2*C) ans=2*X*C+(Y-X)*B;
      else ans=2*Y*C;
    }
    else{
      if(A<2*C) ans=2*Y*C+(X-Y)*A;
      else ans=2*X*C;
    }
  }

  cout << ans << endl;
  
  return 0;
}
