#include <iostream>

using namespace std;

int main(){
  int A,B,C,X,Y;

  cin >> A >> B >> C >> X >> Y;
  int priceAB=0,priceC=0;
  int goodprice = 0;
  if(X > 0 && Y > 0){
    priceAB = A+B;
    priceC = C*2;
    if(priceAB > priceC) goodprice = priceC;
    else goodprice = priceAB;
  }

  int total = 0;
  while(X > 0 && Y > 0){
    total+= goodprice;
    X--;
    Y--;
  }

  if(X > 0){
    priceAB =A;
    if(priceAB < priceC) goodprice = priceAB;
  }

  while(X > 0){
    total += goodprice;
    X--;
  }

  if(Y > 0){
    priceAB =B;
    if(priceAB < priceC) goodprice = priceAB;
  }

  while(Y > 0){
    total += goodprice;
    Y--;
  }

  cout << total << endl;

  return 0;
}
