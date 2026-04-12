#include <iostream>
using namespace std;
int main()
{
  int X;
  cin >> X;
  string ans = "NO";
  if (X == 7 || X == 5 || X == 3)
  {
    ans = "YES";
  }
  cout << ans << endl;
  return 0;
}