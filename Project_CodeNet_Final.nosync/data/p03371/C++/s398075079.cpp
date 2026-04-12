#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;
int main(){
  ll A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  if(2 * C > A + B){
    cout << X * A + Y * B << endl;
  }
  else{
    if(X > Y){
      cout << 2 * C * Y + min(A*(X-Y), 2*C*(X-Y)) << endl;
    }
    else if(Y >= X){
      cout << 2 * C * X + min(B*(Y-X),2*C*(Y-X)) << endl;
    }
  }

}
