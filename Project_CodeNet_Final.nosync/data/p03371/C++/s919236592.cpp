#include <iostream>
using namespace std;

int main(){
  int A, B, C, X, Y;
  cin >> A  >> B >> C >> X >> Y;
  int price=0;

  int q;
  q = max(X, Y);

  int Z = min(X, Y);
  if (A+B>2*C) {
    price += 2*C*Z;
  } else {
    price += Z*(A+B);
  }

  if (q==X){
    if (A>2*C) price += 2*C*(q-Z);
    else price += A*(q-Z);
  } else if (q==Y){
    if (B>2*C) price += 2*C*(q-Z);
    else price += B*(q-Z);
  }

  cout << price << endl;
}