#include <iostream>
using namespace std;

int main()
{
  string S;
  cin >> S;
  if((S[0] == S[1]) &&
    (S[1] == S[2]) &&
    (S[2] == S[0]))
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  
  return 0;
}