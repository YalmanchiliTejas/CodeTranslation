#include <iostream>

using namespace std;

int main()
{
  char s[5];
  int flaga = 0, flagb = 0;
  cin >> s;
  for (int i = 0; i< 3; i++)
  {
    if (s[i] == 'A') flaga = 1;
    else flagb=1;
  }
  if (flaga && flagb) cout << "Yes";
  else cout << "No";
  return 0;
}