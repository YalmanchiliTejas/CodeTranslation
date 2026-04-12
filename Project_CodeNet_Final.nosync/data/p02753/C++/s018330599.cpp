#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

string S;

int main()
{
  cin >> S;
  if (S == "AAA" || S == "BBB")
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "Yes" << endl;
  }
}