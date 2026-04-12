#include <iostream>
using namespace std;

int main()
{
  int X, Y, Z;
  cin >> X >> Y >> Z;

  int able_to_sit = X / (Y + Z);
  if (X % (Y + Z) - Z < 0) able_to_sit--;

  cout << able_to_sit << endl;

  return 0;
}
