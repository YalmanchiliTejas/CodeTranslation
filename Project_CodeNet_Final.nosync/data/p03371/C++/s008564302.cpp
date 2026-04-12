#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  if((C-A) + (C-B) < 0){
    if(X >= Y){
      cout << min((2*C*Y + A*(X-Y)),(2*C*X)) << endl;
    } else{
      cout << min((2*C*X + B*(Y-X)),(2*C*Y)) << endl;
    }
  } else {
    cout << (A*X + B*Y) << endl;
  }
  return 0;
}
