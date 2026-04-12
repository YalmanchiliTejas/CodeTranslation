#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main(){
  ll A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  ll ans = 0LL;
  if(A+B >= 2*C){
    ll tmp = min(X,Y);
    ans += tmp * 2 * C;
    X -= tmp;
    Y -= tmp;
  }

  if(X>0 && Y>0){
    ans += X*A + Y*B;
    cout << ans << endl;
    return 0;
  }
  else if(X>0 && Y==0){
    if(A>=2*C){
      //Cで払う
      ans += X * 2 * C;
    }else{
      //Aで払う
      ans += X * A;
    }
    cout << ans << endl;
    return 0;
  }
  else if(X==0 && Y>0){
    if(B>=2*C){
      //Cで払う
      ans += Y * 2 * C;
    }else{
      //Bで払う
      ans += Y * B;
    }
    cout << ans << endl;
    return 0;
  }

  cout << ans << endl;
  return 0;
}