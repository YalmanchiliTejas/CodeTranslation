
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string S;
  cin >> S;
  cout << (((S[0] == S[1]) && (S[1] == S[2])) ? "No" : "Yes");
  return 0;
}
