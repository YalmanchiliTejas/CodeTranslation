#include <iostream>

using namespace std;

int main()
{
  int A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;

  X *= 2;
  Y *= 2;

  int common = min(X,Y);
  int price = 0;
  
  {
    int price_C = common * C;
    int price_AB = common/2 * (A+B);
    price += min(price_C, price_AB);
  }
  
  if (X>Y) {
    int residue_X = X - common;
    int price_A = residue_X/2 * A;
    int price_C = residue_X * C;
    price += min(price_A,price_C);
  } else if (Y>X) {
    int residue_Y = Y - common;
    int price_B = residue_Y/2 * B;
    int price_C = residue_Y * C;
    price += min(price_B,price_C);
  }

  cout << price << endl;
  
  return 0;
}