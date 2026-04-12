#include <iostream>
using namespace std;

string test()
{
  int test, pass;
  cin >> test >> pass;

  if(test == pass)
  return "Yes";

  else
  return "No";
}

int main()
{
  cout << test() << endl;
}
