#include <iostream>

using namespace std; 

int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int price = A * X + B * Y;
  for (int c = 2; c < max(X, Y) * 2 + 1; c += 2)
  {
    int newPrice = C * c + max(0, (X - c / 2) * A) + max(0, (Y - c / 2) * B);
    if (newPrice < price)
    {
      price = newPrice;
    }
    else 
    {
      break; 
    }
  }

  cout << price << endl;
}