#include<iostream>
using namespace std;
int main (void)
{
  char S[3];
  int i = 0;
  for (auto &e: S)
  {
    cin >> e;
    i += (int) (e - 'A');
  }
  if (i == 0 || i == 3)
  {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
