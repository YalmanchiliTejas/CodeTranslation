#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  if(A+B <= 2 * C){
    cout << X * A + Y * B << endl;
  }else{
    if(X == Y){
      cout << 2 * X * C << endl;
    }else if(X > Y){
      cout << Y * 2 * C + (X-Y)*min(A,2*C) << endl;
    }else{
      cout << X * 2 * C + (Y-X)*min(B,2*C) << endl;
    }
  }
}
