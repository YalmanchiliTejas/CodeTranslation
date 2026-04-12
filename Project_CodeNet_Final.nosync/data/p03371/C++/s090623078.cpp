#include <iostream>
using namespace std;

int MIN(int a, int b)
{
  if (a < b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

int MAX(int a, int b)
{
  if (b < a)
  {
    return a;
  }
  else
  {
    return b;
  }
}

int main()
{
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int all_AB = 2 * C * MAX(X, Y);
  int no_AB = A * X + B * Y;
  int partial_AB = A * (X - MIN(X, Y)) + B * (Y - MIN(X, Y)) + 2 * C * MIN(X, Y);

  int min = MIN(MIN(all_AB, no_AB), partial_AB);

  cout << min << endl;
}