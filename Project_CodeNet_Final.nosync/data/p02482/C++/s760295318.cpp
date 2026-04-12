#include <iostream>
#include <string>

using namespace std;

string solve(int a, int b)
{
  if(a < b) return "a < b";
  if(a > b) return "a > b";
  return "a == b";
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << solve(a,b) << endl;
  return 0;
}